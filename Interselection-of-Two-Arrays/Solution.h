//
// Created by mark on 2019/1/24.
//

#ifndef INTERSELECTION_OF_TWO_ARRAYS_SOLUTION_H
#define INTERSELECTION_OF_TWO_ARRAYS_SOLUTION_H

#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	static vector<int> intersection(vector<int> &nums1, vector<int> &nums2){
		set<int> *set1 = new set<int>;
		for (int num : nums1){
			set1->insert(num);
		}
		vector<int> vector1;
		for (int num : nums2){
			for (auto iterator1 = set1->begin(); iterator1 != set1->end(); iterator1++){
				if(*iterator1 == num){
					vector1.push_back(num);
					iterator1++; /* if you don't do this, then iterator will become null after erase(); */
					set1->erase(num);
				}
			}
		}
		return vector1;
	}
};


#endif //INTERSELECTION_OF_TWO_ARRAYS_SOLUTION_H
