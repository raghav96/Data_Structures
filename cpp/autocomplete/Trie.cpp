#include "util.hpp"
#include "Trie.hpp"
#include "limits.h"
#include <stdio.h>
#include <stdlib.h>

TrieNode::TrieNode(){
	isWord = false;
	freq = INT_MIN;
	max_freq = INT_MIN;
	for (int i=0; i<27; i++){
		children.push_back(NULL);
	}
};

TrieNode::~TrieNode(){
	;
};

Trie::Trie(){
	root = new TrieNode;
	valid_node_count = 0;
	char val;
	for (int i = 0 ; i < 26; i++){
		val = 'a' + i;
		index[val] = i;
		letter[i] = val;
	}
	index[26] = ' ';
	letter[' '] = 26;

};

bool Trie::insert(std::string word, unsigned int freq){
	if (word == ""){
		return false;
	}
	TrieNode * trav = root;
	for (int i = 0; i < word.length(); i++){

		/* Illegal characters */
		if(word[i] < 'a' || word[i] > 'z' || word[i] != ' '){
			return false;
		}

		if(trav->children[index[(char)word[i]]] == NULL){
			trav->children[index[(char)word[i]]] = new TrieNode();
		}

		trav = trav->children[index[(char)word[i]]];
	}

	if(trav->isWord){
		return false;
	}
	trav->isWord = true;
	trav->freq = freq;
	trav->max_freq = std::max(trav->max_freq, (int) freq);
	valid_node_count++;

	trav = root;
	for(int i = 0; i < word.length(); i++){
		trav->max_freq = std::max(trav->max_freq, (int) freq);
		trav = trav->children[index[(char)word[i]]];
	}

	return true;
	
};

bool Trie::find(std::string word){
	if (word == ""){
		return false;
	}
	if (root == NULL){
		return false;
	}
	TrieNode * trav = root;

	for (int i=0; i<word.length(); i++){
		if(trav->children[index[(char)word[i]]]){
			trav->children[index[(char)word[i]]];
		}
		else{
			return false;
		}
	}
	return trav->isWord;
};

void Trie::print(){

	TrieNode * trav = root;
	std::priority_queue<TrieNode *> q;

	q.push(trav);
	while(!q.empty()){
		trav = q.top();
		q.pop();
		cout << "isWord:" << trav->isWord << " freq:" << trav->freq << " max_freq:" << trav->max_freq;
		for (int i = 0; i < trav->children.size(); i++){
			if(trav->children[i]){
				q.push(trav->children[i]);
			}
		}
	}

};

std::vector<std::string> Trie::predictCompletions(std::string prefix, unsigned int num_completions){
	std::vector<std::string> words;
	if(prefix.length() == 0){
		return words;
	}
	if(num_completions <= 0){
		return words;
	}
	if(root == NULL){
		return words;
	}

	// Setting the starting node to be the root
	TrieNode * node = root;

	// Traversing to node where the prefix exists
	for(int i = 0; i < prefix.length(); i++){
		if(prefix[i] < 'a' || prefix[i] > 'z' || prefix[i] == ' '){
			return words;
		}
		if (node->children[(char)index[prefix[i]]] != NULL){
			return words;
		}
		node = node->children[(char)index[prefix[i]]];
	}

  	/* Forming strings through traversal of the trie and priority*/
	std::priority_queue<std::pair<TrieNode*, std::string>, std::vector<std::pair<TrieNode*, std::string> >, TrieNodePairCompMin> completions;//compiles list of completions
	TrieNode* subroot = node;


	std::priority_queue<std::pair<TrieNode*, std::string>, std::vector<std::pair<TrieNode*, std::string> >, TrieNodePairCompMax> buffer;//compares max_freq
	
	// Starting out empty string to construct rest of word
	std::pair<TrieNode*, std::string> tmp(subroot, "");
	
	// Step 1 Greedy Algorithm: making the min_freq to be minimum in order to greedily obtain highest min_freq
	int min_freq = INT_MIN;
	buffer.push(tmp);
	
	// Checking if buffer is empty if all the possible completions are over
	// Step 2: Traversing through all the nodes of the trie
	while(!buffer.empty()){

		// Taking out the top element to traverse
		tmp = buffer.top();
		buffer.pop();

		// If the top element is word then we can add it completions
		if(tmp.first->isWord){
			// If the completions are not full then add to completions
			if (completions.size() < num_completions){
				completions.push(tmp);
			}
			// Updating the completions to follow branches with more min_freq
			else {
				//Step 3 Greedy algorithm: If there is a higher min_freq then update
				if(tmp.first->freq > min_freq){
					completions.pop();
					completions.push(tmp);
					min_freq = completions.top().first->freq;
				}
			}
		}
		// Inserting all the children of the node into the buffer to traverse through the trie
		for (int i = 0; i < tmp.first->children.size(); i++){
			// Add the node and the constructed substring into the buffer to constuct substring
			if(tmp.first->children[i] && tmp.first->max_freq > min_freq){
				std::pair<TrieNode *, std::string> new_pair(tmp.first->children[i], tmp.second + letter[i]);
				buffer.push(new_pair);
			}
		}
	}

	// Pop the completions to construct the words
	while(!completions.empty()){
		words.push_back(prefix + completions.top().second);
		completions.pop();
	}
	// Return in reverse so we get more frequent completions at the top
	reverse(words.begin(), words.end());
  	return words;

};

Trie::~Trie(){
	deleteAll(root);
};

void Trie::deleteAll(TrieNode * root){
	if (root == NULL){
		return ;
	}

	for(int j = 0; j < root->children.size(); j++)
		deleteAll(root->children[j]);

	delete root;
}