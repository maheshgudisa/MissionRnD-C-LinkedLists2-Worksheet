/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1, *temp2, *prev;
	if (head1 == NULL && head2 == NULL)return NULL;
	if (head1 == NULL)return head2;
	if (head2 == NULL)return head1;
	temp1 = head1;
	temp2 = head2;
	prev = head1;
	while (true){
		if (temp2 == NULL)break;
		else if (temp1->num > temp2->num && temp1 == head1){
			head2 = temp2->next;
			temp2->next = head1;
			head1 = temp2;
			temp1 = head1;
			temp2 = head2;
		}
		else if (temp1->next == NULL &&temp1->num <= temp2->num){
			temp1->next = temp2;
			temp2 = NULL;
		}
		else if (temp1->num <= temp2->num){
			prev = temp1;
			temp1 = temp1->next;
		}
		else if (temp1->num>temp2->num){
			head2 = temp2->next;
			prev->next = temp2;
			temp2->next = temp1;
			prev = temp2;
			temp2 = head2;

		}
		
		
	}

	return head1;
}
