#include <iostream>
#include "Solution.h"

int main() {
	vector<int> nums = {4,1,-1,2,-1,2,3};
	int k = 2;
	vector<int> res = Solution::topKFrequent(nums,k); /* how to handle the repeated element */
	for(int num : res){
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}