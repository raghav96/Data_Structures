#include <iostream>
#include <fstream>
#include "Trie.hpp"
#include "util.hpp"
using namespace std;

int main(){
	/* test case 1*/
	
	Trie dict;
	cout<<dict.insert("hello",5)<<endl;
	cout<<dict.insert("hell",1)<<endl;
	cout<<dict.insert("and",10)<<endl;
	cout<<dict.insert("dog",15)<<endl;
	cout<<dict.insert("alphabet",3)<<endl;
	cout<<dict.insert("world",4)<<endl;
	cout<<dict.find("and")<<endl;
	cout<<dict.find("dog")<<endl;
	cout<<dict.find("hel")<<endl;
	cout<<dict.find("g")<<endl;
	dict.print();

	/* test case 4*/
	Trie dict2;
	ifstream infile;
	infile.open("unique_freq_dict.txt");
	Utils::load_dict(dict2, infile);
	infile.close();
	cout<<dict2.find("and")<<endl;
	cout<<dict2.find("dog")<<endl;
	cout<<dict2.find("hel")<<endl;
	cout<<dict2.find("g")<<endl;
	cout<<dict2.valid_node_count<<endl;
	vector<string> word = dict2.predictCompletions("man", 10);
	for(int i = 0; i < word.size(); i++)
		cout<<word[i]<<endl;
		
	return 0;
}