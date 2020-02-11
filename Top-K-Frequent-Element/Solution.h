//
// Created by mark on 2019/1/25.
//

#ifndef TOP_K_FREQUENT_ELEMENT_SOLUTION_H
#define TOP_K_FREQUENT_ELEMENT_SOLUTION_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
public:
	static vector<int> topKFrequent(vector<int> &nums, int k) {
		assert(k > 0);
		unordered_map<int, int> freq;
		for (int num : nums)
			freq[num] += 1; /* num is a key */
		assert(k <= freq.size());
		/* prioity< Type, Container, Functional > */
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq; /* MinHeap */
		for (unordered_map<int, int>::iterator iter = freq.begin(); iter != freq.end(); iter++) {
			pq.push(make_pair(iter->second, iter->first));
		}
		vector<int> res;
		while (!pq.empty() && k > 0) {
			res.push_back(pq.top().second);
			pq.pop();
			k--;
		}
		sort(res.begin(), res.end());
		return res;
	}
};


#endif //TOP_K_FREQUENT_ELEMENT_SOLUTION_H
