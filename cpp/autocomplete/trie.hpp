/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 *  Modified by: Raghav Ravisankar
 *  Date: 20170826
 */

#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>
#include <algorithm>

/**
 *  The class for a TrieNode.
 *
 */
class TrieNode
{
public:

  /* Create a new Dictionary Node */
  TrieNode();

  /* Destructor */
  ~TrieNode();

  /* attribute */
  bool isWord;
  int freq;
  int max_freq;
  std::vector<TrieNode*> children;

};

/**
 *  The class for a TrieNode comparison within a priority queue.
 *  Min heap with freq attribute.
 *
 */
class TrieNodePairCompMin {
public:
    bool operator()(std::pair<TrieNode*, std::string>& lhs, std::pair<TrieNode*, std::string>& rhs) const {
        return lhs.first->freq > rhs.first->freq;
    }
};

/**
 *  The class for a TrieNode comparison within a priority queue.
 *  Max heap with max_freq attribute.
 *
 */
class TrieNodePairCompMax {
public:
    bool operator()(std::pair<TrieNode*, std::string>& lhs, std::pair<TrieNode*, std::string>& rhs) const {
        return lhs.first->max_freq < rhs.first->max_freq;
    }
};

/**
 *  The class for a dictionary ADT, implemented as a mulit-way trie.
 *
 */
class Trie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  Trie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word);

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~Trie();

  /* Core for Destructor */
  void deleteAll(TrieNode* root);

  /* print the subtree for debugging*/
  void print();

  /* Used for check the number of total nodes in the trie*/
  int valid_node_count;

  private:

    TrieNode* root; //root fo the trie
    std::unordered_map<char, int> index; //map character to corresponding index
    std::unordered_map<int, char> letter; // map index to corresponding character

};

#endif // _TRIE_HPP