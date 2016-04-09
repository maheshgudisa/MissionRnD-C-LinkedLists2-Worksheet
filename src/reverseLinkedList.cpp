/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head != NULL){
		node *prev = NULL,*temp;
		while (head != NULL){
			temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		return prev;
	}
	return NULL;
}
