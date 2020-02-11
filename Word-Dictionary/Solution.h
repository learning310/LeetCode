//
// Created by mark on 2019/1/28.
//

#ifndef WORD_DICTIONARY_SOLUTION_H
#define WORD_DICTIONARY_SOLUTION_H

#include <map>

using namespace std;

class WordDictionary {
private:
	class Node {
	public:
		bool isWord;
		map<char, Node> next;

		Node() : isWord(false), next() {}
	};

	Node *root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node *cur = root;
		for (int i = 0; i < word.size(); ++i) {
			char c = word.at(i);
			if (cur->next.find(c) == cur->next.end()) {
				cur->next.insert(std::pair<char, Node>(c, Node()));
			}
			cur = &cur->next.find(c)->second;
		}
		cur->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return match(root, word, 0);
	}


	bool match(Node *node, string word, int index) {
		if (index == word.length()) {
			return node->isWord;
		}

		char c = word.at(index);
		if (c != '.') {
			if (node->next.find(c) == node->next.end())
				return false;
			return match(&node->next.find(c)->second, word, index + 1);
		} else {
			for (auto iter = node->next.begin(); iter != node->next.end(); iter++) {
				if (match(&node->next.find(iter->first)->second, word, index+1) )
					return true;
			}
			return false;
		}
	}
};


#endif //WORD_DICTIONARY_SOLUTION_H
