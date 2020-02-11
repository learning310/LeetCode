//
// Created by mark on 2019/1/22.
//

#ifndef UNIQUEMORSECODEWORDS_SOLUTION_H
#define UNIQUEMORSECODEWORDS_SOLUTION_H

#include <set>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
	int uniqueMorseRepresentation(std::vector<std::string> &words){
		std::vector<std::string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
		                                  ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
		                                  ".--", "-..-", "-.--", "--.."};
		std::set<std::string> Set;
		for(const std::string &word : words){
			std::cout << '"' << word << '"' << "->";
			std::string code;
			for(char c : word){
				code += morse[c-'a'];
			}
			std::cout << '"' << code << '"' << std::endl;
			Set.insert(code);
		}
		return (int)Set.size();
	}
};


#endif //UNIQUEMORSECODEWORDS_SOLUTION_H
