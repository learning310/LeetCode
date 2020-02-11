//
// Created by mark on 2019/1/16.
//

#ifndef VALID_PARENTHESES_SOLUTION_H
#define VALID_PARENTHESES_SOLUTION_H

#include <stack>
#include <string>

class Solution {
public:
	bool isValid(std::string s){
		std::stack<char> *stack = new std::stack<char>();
		for (int i = 0; i < s.size(); ++i) {
			char c = s.at(i);
			if( c == '(' || c == '{' || c == '['){
				stack->push(c);
			}else{
				if(stack->empty()){
					return false;
				}

				char topChar = stack->top();
				if( c == ')' && topChar != '(' ){
					return false;
				}
				if( c == ']' && topChar != '[' ){
					return false;
				}
				if( c == '}' && topChar != '{' ){
					return false;
				}
				stack->pop();
			}
		}
		return stack->empty();
	}
};

#endif //VALID_PARENTHESES_SOLUTION_H
