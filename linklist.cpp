// linklist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
// A linked list node 
struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node;
// push infront of
void push(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

void insertAfter(Node* pre, int new_data)
{
	// 1 check if give pre is null
	if (pre == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}
	// 2 allocate 
	Node * new_node = (Node *)malloc(sizeof(Node));
		// 3 put data in new
	new_node->data = new_data;
		// 4 pre 's next = newnode
//	pre->next = new_node;
	// 5  new node's next = pre's next
//	new_node->next = pre->next;
	//4  new node's next = pre's next   prepare   ===== cause ->9 loop
	new_node->next = pre->next;
// 5 pre 's next = newnode --- connect
	pre->next = new_node;
}
#if 0
void insertAfter(Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		printf("the given previous node cannot be NULL");
		return;
	}
	/* 2. allocate new node */
	Node* new_node = (Node*)malloc(sizeof(Node*));
		/* 3. put in the data */
	new_node->data = new_data;
		/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;
	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}
#endif

// add after last node  6 steps
void append(Node ** headref, int data)
{ //  1  -- malloc 
	Node * newNode = (Node*)malloc(sizeof(Node*));
	Node * last = *headref;

  //  2  put data
	newNode->data = data;
 
  //  3  set newnode->next null
	newNode->next = NULL;

  //  4  if empty list 
	if (*headref == NULL)
	{
		*headref = newNode;
		return;
	}
  //  5  not empty move to end 
	else
	{
		while (last ->next != NULL)
		last = last->next;
	}
  //  6  last set to newnodw
	last ->next = newNode;
}

void printlist(Node *node)
{	
	while (node != NULL)
	{
		printf("%d->", node->data);
		node = node->next;		
	}
}
int main()
{	
	Node * head =NULL;
	push(&head, 1);	
	push(&head, 2);
	push(&head, 3);
	printlist(head);
	printf("inserting\n");
	insertAfter(head->next, 8);
	insertAfter(head, 9);
	printlist(head);
	printf("Appending\n");
	append(&head, 100);
	printlist(head);
	getchar();
    return 0;
}

