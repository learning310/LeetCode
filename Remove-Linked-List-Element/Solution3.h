//
// Created by mark on 2019/1/18.
//

#ifndef REMOVE_LINKED_LIST_ELEMENT_SOLUTION3_H
#define REMOVE_LINKED_LIST_ELEMENT_SOLUTION3_H

#include "ListNode.h"

class solution3{
public:
	ListNode* removeElements(ListNode *head, int val){
		if(head == nullptr)
			return head;
		/*
		ListNode *res = removeElements(head->next, val);
		if(head->val == val){
			head->next = nullptr;
			delete head;
			return res;
		} else{
			head->next = res;
			return head;
		}
		*/
		head->next = removeElements(head->next, val);
		if (head->val == val){
			ListNode *delNode = head;
			head = head->next;
			delete delNode;
			return head;
		} else {
			return head;
		}
	}
};

#endif //REMOVE_LINKED_LIST_ELEMENT_SOLUTION3_H
