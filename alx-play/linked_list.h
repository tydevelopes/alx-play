//
//  linked_list.h
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/30/23.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *node_ptr;

typedef struct node {
	int data;
	struct node *next;
}node;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t _print_list(const node *head);
node *insert_at_front(node **head, const int data);
node *insert_at_end(node **head, const int data);
void _free_list(node *head);

#endif /* linked_list_h */
