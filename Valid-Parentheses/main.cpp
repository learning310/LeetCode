#include <iostream>
#include "solution.h"

int main() {
	std::cout <<  Solution().isValid("(){}")  << std::endl;
	std::cout <<  Solution().isValid("()[{}")  << std::endl;
	return 0;
}