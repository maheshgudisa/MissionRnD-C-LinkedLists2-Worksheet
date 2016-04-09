/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *temp,*new_node,*curr;
	int track = 1;
	curr = head;
	if (K <= 0||head==NULL)return NULL;
	else{
		while (curr != NULL){
			if (track == K){
				new_node = (node *)malloc(sizeof(node));
				new_node->num = K;
				new_node->next = curr->next;
				curr->next = new_node;
				curr = curr->next;
				track = 0;
			}
			track++;
			curr = curr->next;
		}
		return head;
	}
}
