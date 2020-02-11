#include <iostream>
#include "Solution.h"
#include <vector>
#include <map>
using  namespace std;

static vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
	map<int, int> map1;
	for (int i = 0; i < nums1.size(); ++i){
		map1[nums1[i]] = map1[nums1[i]] + 1;
	}
	vector<int> res;
	for (int i = 0; i < nums2.size(); ++i) {
		if ( map1[nums2[i]] > 0){
			res.push_back(nums2[i]);
			map1[nums2[i]]--;
		}
	}
	return res;
}

int main() {
	vector<int> vector1 = {1, 2, 2, 3, 4, 5, };
	vector<int> vector2 = {2, 2, };
	vector<int> vector3;
	Solution solution;
	/*
	vector3 = solution.intersection(vector1, vector2);
	for (int num : vector3){
		cout << vector3.front() << endl;
		vector3.pop_back();
	}
	 */
	vector3 = intersection(vector1, vector2);
	for (int num : vector3){
		cout << vector3.front() << endl;
		vector3.pop_back();
	}
	return 0;
}