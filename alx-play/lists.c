//
//  lists.c
//  alx-play
//
//  Created by Emmanuel Adjei-Frimpong on 3/30/23.
//

#include "linked_list.h"

/**
 * print_list - prints all elements of a list
 * @h: pointer to a list
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t length = 0;
	const list_t *temp = NULL;
	
	if (!h)
		return (length);
	temp = h;
	while (temp)
	{
		length++;
		if (temp->str)
			printf("[%u] %s\n", temp->len, temp->str);
		else
			printf("[0] (nil)\n");
		temp = temp->next;
	}
	return (length);
}

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to the list
 * Return: number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t length = 0;
	const list_t *temp = NULL;
	
	if (!h)
		return (length);
	temp = h;
	while (temp)
	{
		if (temp->str)
			length++;
		temp = temp->next;
	}
	return (length);
}

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to head pointer to the list
 * @str: pointer to the string to add
 * Return: pointer to the new element
 */
list_t *_add_node(list_t **head, const char *str)
{
	list_t *temp = NULL;
	
	if (!str)
		return (NULL);
	
	temp = malloc(sizeof(list_t));
	
	if (!temp)
		return (NULL);
	
	temp->str = strdup(str);
	
	if (!temp->str)
	{
		free(temp);
		return (NULL);
	}
	
	temp->len = (unsigned int)strlen(str);
	temp->next = NULL;
	
	if (!head)
	{
		*head = temp;
		return (temp);
	}
	temp->next = *head;
	*head = temp;
	
	return (temp);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to head pointer to the list
 * @str: pointer to the string to add
 * Return: pointer to the new element
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *temp = NULL;
	list_t *curr_node = NULL;
	
	if (!str)
		return (NULL);
	
	temp = malloc(sizeof(list_t));
	
	if (!temp)
		return (NULL);
	
	temp->str = strdup(str);
	
	if (!temp->str)
	{
		free(temp);
		return (NULL);
	}
	
	temp->len = (unsigned int)strlen(str);
	temp->next = NULL;
	
	if (!*head)
	{
		*head = temp;
		return (temp);
	}
	curr_node = *head;
	
	while (curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = temp;
	
	return (temp);
}

/**
 * free_list - frees a list_t list
 * @head: pointer to begining of list
 */
void free_list(list_t *head)
{
	list_t *curr_node = NULL;
	
	if (!head)
		return;
	
	curr_node = head;
	
	while (head->next)
	{
		head = head->next;
		free(curr_node->str);
		free(curr_node);
		curr_node = head;
	}
	free(head->str);
	free(head);
}
