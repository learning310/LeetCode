#include <iostream>
#include <ctime>
#include "Solution.h"
#include "Solution2.h"
#include "Solution3.h"

int sum_re(int arr[], int length, int left = 0){
	if(left == length){
		return 0;
	} else {
		int ret = arr[left] + sum_re(arr, length, left+1); /* small + big */
		return  ret;
	}

}
/* About Recursion
 * include:
 * 1. judge condition(for terminate)
 * 2. move complex problem to easy problem.
 */

int main() {
	/*
	int opCount = 10000;
	int arr[opCount];
	for (int i = 0; i < opCount; ++i) {
		arr[i] = i;
	}
	clock_t startTime = clock();
	sum_re(arr, opCount);
	clock_t endTime = clock();
	std::cout << (double)(endTime - startTime) / CLOCKS_PER_SEC;
	*/

	int arr[] = {1,2,3,10};
	ListNode  *listNode= new ListNode(arr, sizeof(arr)/sizeof(arr[0]));
	solution3 test;
	test.removeElements(listNode,10);

	return 0;
}
