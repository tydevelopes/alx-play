//
//  linked_list.c
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/30/23.
//

#include "linked_list.h"

node *insert_at_front(node **head, const int data) {
	node *temp = malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	
	if (!*head) {
		*head = temp;
		return temp;
	}
	temp->next = *head;
	*head = temp;
	
	return temp;
}

node *insert_at_end(node **head, const int data) {
	node *temp = malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	
	node *temp1 = *head;
	
	if (!*head) {
		*head = temp;
		return temp;
	}
	while (temp1->next) {
		temp1 = temp1->next;
	}
	temp1->next = temp;
	
	return temp;
}

size_t _print_list(const node *head){
	size_t length = 0;
	const node *temp = head;
	
	while (temp) {
		length++;
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
	return length;
}

void _free_list(node *head) {
	node *temp = head;
	
	if (!head)
		return;
	while (head->next) {
		head = head->next;
		free(temp);
		temp = head;
	}
	free(head);
}
