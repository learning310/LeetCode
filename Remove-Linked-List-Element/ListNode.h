//
// Created by mark on 2019/1/18.
//

#ifndef REMOVE_LINKED_LIST_ELEMENT_LISTNODE_H
#define REMOVE_LINKED_LIST_ELEMENT_LISTNODE_H

class ListNode{
public:
	int val;
	ListNode *next;
	explicit ListNode(int x):val(x), next(nullptr){}
	ListNode(int arr[], int number){
		this->val = arr[0];
		ListNode *cur = this;
		this->next = nullptr;
		for (int i = 1; i < number; ++i) {
			cur->next = new ListNode(arr[i]);
			cur = cur->next;
		}
	}
};

#endif //REMOVE_LINKED_LIST_ELEMENT_LISTNODE_H
