//
// Created by mark on 2019/1/28.
//

#ifndef MAP_SUM_PAIRS_SOLUTION_H
#define MAP_SUM_PAIRS_SOLUTION_H

#include <map>
#include <string>

using namespace std;

class MapSum {
private:
	class Node {
	public:
		int value;
		map<char, Node> next;

		Node() : value(0), next() {}

		explicit Node(int value) : value(value), next() {}
	};

	Node *root;

	int sum(Node *node) {
//		if(node->next.size() == 0){
//			return node->value;
//		}

		int ret = node->value;
		for (auto iter = node->next.begin(); iter != node->next.end(); iter++) {
			ret += sum(&node->next.find(iter->first)->second);
		}
		return ret;
	}

public:
	/** Initialize your data structure here. */
	MapSum() {
		root = new Node();
	}

	void insert(string key, int val) {
		Node *cur = root;
		for (int i = 0; i < key.length(); ++i) {
			char c = key.at(i);
			if (cur->next.find(c) == cur->next.end()) {
				cur->next.insert(pair<char, Node>(c, Node()));
			}
			cur = &cur->next.find(c)->second;
		}
		cur->value = val;
	}

	int sum(string prefix) {
		Node *cur = root;
		for (int i = 0; i < prefix.length(); ++i) {
			char c = prefix.at(i);
			if (cur->next.find(c) == cur->next.end())
				return 0;
			cur = &cur->next.find(c)->second;
		}
		return sum(cur);
	}
};


#endif //MAP_SUM_PAIRS_SOLUTION_H
