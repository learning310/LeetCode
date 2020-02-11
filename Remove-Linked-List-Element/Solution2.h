//
// Created by mark on 2019/1/18.
//

#ifndef REMOVE_LINKED_LIST_ELEMENT_SOLUTION2_H
#define REMOVE_LINKED_LIST_ELEMENT_SOLUTION2_H

#include "ListNode.h"

class solution2{
public:
	ListNode* removeElements(ListNode *head, int val){
		ListNode *dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode* prev = dummyHead;
		while( prev->next != nullptr ){
			if (prev->next->val == val){
				ListNode *delNode = prev->next;
				prev->next = delNode->next;
				delNode->next = nullptr;
			} else{
				prev = prev->next;
			}
		}
		head = dummyHead->next;
		delete dummyHead;
		return head;
	}
};

#endif //REMOVE_LINKED_LIST_ELEMENT_SOLUTION2_H
