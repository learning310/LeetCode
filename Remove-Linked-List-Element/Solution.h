//
// Created by mark on 2019/1/18.
//

#ifndef REMOVE_LINKED_LIST_ELEMENT_SOLUTION_H
#define REMOVE_LINKED_LIST_ELEMENT_SOLUTION_H

#include "ListNode.h"

class solution{
public:
	ListNode* removeElements(ListNode *head, int val){
		while(head != nullptr != head->val == val){
			ListNode *delNode = head;
			head = head->next;
			delNode->next = nullptr;
		}
		if (head == nullptr){
			return head;
		}
		ListNode* prev = head;
		while( prev->next != nullptr ){
			if (prev->next->val == val){
				ListNode *delNode = prev->next;
				prev->next = delNode->next;
				delNode->next = nullptr;
			} else{
				prev = prev->next;
			}
		}
		return head;
	}
};

#endif //REMOVE_LINKED_LIST_ELEMENT_SOLUTION_H
