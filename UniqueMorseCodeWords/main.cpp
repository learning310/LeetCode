#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
	std::vector<std::string> vec;
	string arr[] = {"love", "relationship", "enthusiastic"};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		vec.push_back(arr[i]);
	}
	Solution test;
	test.uniqueMorseRepresentation(vec);
	return 0;
}