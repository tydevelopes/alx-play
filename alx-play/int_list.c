#include "lists.h"

/**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to the list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t length = 0;
	const listint_t *current_node = NULL;
	
	if (!h)
		return (length);
	
	current_node = h;
	
	while (current_node)
	{
		length++;
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
	return (length);
}

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: pointer to the list
 * Return: number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	size_t length = 0;
	const listint_t *current_node = NULL;
	
	if (!h)
		return (length);
	current_node = h;
	while (current_node)
	{
		length++;
		current_node = current_node->next;
	}
	return (length);
}

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to head pointer to the list
 * @n: number to add
 * Return: pointer to the new element
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *current_node = NULL;
	
	current_node = malloc(sizeof(listint_t));
	
	if (!current_node)
		return (NULL);
	
	current_node->n = (int) n;
	current_node->next = NULL;
	
	if (!head)
	{
		*head = current_node;
		return (current_node);
	}
	current_node->next = *head;
	*head = current_node;
	
	return (current_node);
}

/**
 * add_nodeint_end - adds a new node at the end of a list_t list
 * @head: pointer to head pointer to the list
 * @n: number to add
 * Return: pointer to the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp = NULL;
	listint_t *curr_node = NULL;
	
	temp = malloc(sizeof(listint_t));
	
	if (!temp)
		return (NULL);
	
	temp->n = (int) n;
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
 * free_listint - frees a listint_t list
 * @head: pointer to begining of list
 */
void free_listint(listint_t *head)
{
	listint_t *curr_node = NULL;
	
	if (!head)
		return;
	
	curr_node = head;
	
	while (head->next)
	{
		head = head->next;
		free(curr_node);
		curr_node = head;
	}
	free(head);
}

/**
 * free_listint2 - frees a listint_t list
 * @head: pointer to pointer to begining of list
 */
void free_listint2(listint_t **head)
{
	listint_t *curr_node = NULL;
	
	if (!head || !*head)
		return;
	
	curr_node = *head;
	
	while ((*head)->next)
	{
		*head = (*head)->next;
		free(curr_node);
		curr_node = *head;
	}
	free(*head);
	
	*head = NULL;
}

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to head pointer to the list
 * Return: pointer to the ndeleted node
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *removed_node = NULL;
	
	if (!head || !*head)
	{
		return (0);
	}
	removed_node = *head;
	*head = (*head)->next;
	
	n = removed_node->n;
	
	free(removed_node);
	
	return (n);
}

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to begining of list
 * @index: index of the node
 * Return: node at index or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current_node = head;
	unsigned int current_index = 0;
	
	if (!current_node)
		return (NULL);
	
	while (current_index != index)
	{
		if (!current_node->next)
			return (NULL);
		current_node = current_node->next;
		current_index++;
	}
	return (current_node);
}

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: pointer to head of the list
 * Return: sum of data in list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current_node = head;
	
	if (!current_node)
		return (0);
	
	while (current_node)
	{
		sum += current_node->n;
		current_node = current_node->next;
	}
	return (sum);
}

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to head pointer to the list
 * @idx: index of the list where the new node should be added
 * @n: number to insert
 * not elegant
 */
listint_t *_insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current_node = *head;
	unsigned int current_index = 0;
	listint_t *temp = NULL;
	
	if (!head || (!current_node && idx != 0))
		return (NULL);
	
	temp = malloc(sizeof(listint_t));
	if (!temp)
		return (NULL);
	temp->n = n;
	temp->next = NULL;
	
	if (idx == 0)
	{
		/* List is empty and index to insert at is 0 */
		if (!current_node)
		{
			*head = temp;
			return (temp);
		}
		
		/* One or more node and index to insert at is 0 */
		temp->next = *head;
		*head = temp;
		return (temp);
	}
	
	while (current_index < idx)
	{
		/* At the end of list */
		if (!current_node->next)
		{
			if (current_index + 1 == idx)
			{
				current_node->next = temp;
				return (temp);
			}
			free(temp);
			return (NULL);
		}
		/* In between two nodes */
		else
		{
			if (current_index + 1 == idx)
			{
				temp->next = current_node->next;
				current_node->next = temp;
				return  (temp);
			}
			current_node = current_node->next;
			current_index++;
		}
	}
	free(temp);
	return (NULL);
}

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to head pointer to the list
 * @idx: index of the list where the new node should be added
 * @n: number to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current_node = *head;
	listint_t *previous_node = NULL;
	listint_t *temp = NULL;
	unsigned int current_index = 0;
	
	if (!head || (!current_node && idx != 0))
		return (NULL);
	
	temp = malloc(sizeof(listint_t));
	if (!temp)
		return (NULL);
	temp->n = n;
	temp->next = NULL;
	
	while (current_index != idx && current_node)
	{
		previous_node = current_node;
		current_node = current_node->next;
		current_index++;
	}
	if (!current_node && idx == 0)
		*head = temp;
	else if (!previous_node)
	{
		temp->next = current_node;
		*head = temp;
	}
	else if (current_index == idx)
	{
		previous_node->next = temp;
		temp->next = current_node;
	}
	else
	{
		free(temp);
		temp = NULL;
	}
	return (temp);
}

/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t linked list.
 * @head: pointer to head pointer to the list
 * @index: index of node to be deleted
 * Not so elegant
 */
int _delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node = *head;
	unsigned int current_index = 0;
	listint_t *temp = NULL;
	
	if (!head || !current_node)
		return (-1);
	
	if (index == 0)
	{
		/* One or more node and index to insert at is 0 */;
		*head = (*head)->next;
		free(current_node);
		return (1);
	}
	
	while (current_index < index)
	{
		if (current_index + 1 == index)
		{
			if (current_node->next)
			{
				if (!current_node->next->next)
				{
					temp = current_node->next;
					current_node->next = NULL;
				}
				else
				{
					temp = current_node->next;
					current_node->next = current_node->next->next;
				}
				free(temp);
				return (1);
			}
			else
				return (-1);
		}
		else
		{
			current_node = current_node->next;
			current_index++;
		}
	}
	return (-1);
}

/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t linked list.
 * @head: pointer to head pointer to the list
 * @index: index of node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node = *head;
	listint_t *previous_node = NULL;
	unsigned int current_index = 0;
	
	if (!head || !current_node)
		return (-1);
	
	while (current_index != index && current_node)
	{
		previous_node = current_node;
		current_node = current_node->next;
		current_index++;
	}
	if (!current_node)
		return (-1);
	if (!previous_node)
		*head = current_node->next;
	else
		previous_node->next = current_node->next;
		
	free(current_node);
	return (1);
}

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to head pointer to the list
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous_node = NULL;
	listint_t *current_node = *head;
	
	if (!head || !*head)
		return (NULL);
	
	while (current_node->next)
	{
		current_node = current_node->next;
		(*head)->next = previous_node;
		previous_node = *head;
		*head = current_node;
	}
	(*head)->next = previous_node;
	
	return (*head);
}

int contains_address(const listint_t *array[], const listint_t *node);

/**
 * print_listint_safe - prints all elements of a listint_t list
 * @head: pointer to the list
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t length = 0;
	const listint_t *current_node = NULL;
	const listint_t *array[1024] = {NULL};
	
	if (!head)
		return (0);
	
	current_node = head;
	
	while (current_node)
	{
		if (contains_address(array, current_node))
		{
			printf("-> [%p] %d\n", current_node ,current_node->n);
			break;
		}
			
		array[length] = current_node;
		
		length++;
		printf("[%p] %d\n", current_node ,current_node->n);
		current_node = current_node->next;
	}
	return (length);
}

/**
 * contains_address - checks if array contains given node
 * @array: array of pointers to listint_t
 * @node: node to search
 * Return: 1 if found, 0 otherwise
 */
int contains_address(const listint_t *array[], const listint_t *node)
{
	int i = 0;
	
	while (array[i])
	{
		if (array[i] == node)
			return (1);
		i++;
	}
	return (0);
}

/**
 * free_listint_safe - prints all elements of a listint_t list
 * @head: pointer head point to the list
 * Return: size of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	listint_t *current_node = NULL;
	const listint_t *array[1024] = {NULL};
	
	if (!h || !*h)
		return (0);
	
	current_node = *h;
	
	while (*h)
	{
		if (contains_address(array, *h))
		{
			break;
		}
		
		array[length] = *h;
		
		length++;
		*h = (*h)->next;
		free(current_node);
		current_node = *h;
	}
	*h = NULL;
	return (length);
}

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the list
 * Return: address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	const listint_t *node_ptr_A = head;
	const listint_t *node_ptr_B = head;
	
	if (!head)
		return (NULL);
	
	/* find the meeting point of the two pointers */
	while (node_ptr_B && node_ptr_B->next)
	{
		node_ptr_A = node_ptr_A->next;
		node_ptr_B = node_ptr_B->next->next;
		
		if (node_ptr_A == node_ptr_B)
		{
			/* there is a loop in the linked list */
			break;
		}
	}
	
	/* no loop detected */
	if (!node_ptr_B || !node_ptr_B->next)
	{
		return NULL;
	}
	
	/* move one pointer to the head of the list and advance both pointers until they meet again */
	node_ptr_A = head;
	while (node_ptr_A != node_ptr_B)
	{
		node_ptr_A = node_ptr_A->next;
		node_ptr_B = node_ptr_B->next;
	}
	
	/* the node where the loop starts is the meeting point */
	return (listint_t *)node_ptr_A;
}

/**
 The above implementation uses two pointers, slow_ptr and fast_ptr, to traverse the linked list. The fast_ptr moves at a faster pace than the slow_ptr, and if there is a loop in the linked list, the two pointers will eventually point to the same node. The algorithm first finds the meeting point of the two pointers by advancing the pointers until they point to the same node. If there is no loop in the linked list, the fast_ptr will reach the end of the list and the algorithm returns NULL. If there is a loop, the slow_ptr is moved to the head of the list and both pointers are advanced at the same pace until they meet again at the node where the loop starts.
 
 This implementation does not use an array, malloc or free, and it has a time complexity of O(n), where n is the number of nodes in the linked list.
 */
