
// linklist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>


/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node *head, int n)
{
	struct Node *main_ptr = head;
	struct Node *ref_ptr = head;

	int count = 0;
	if (head != NULL)
	{
		while (count < n)
		{
			if (ref_ptr == NULL)
			{
				printf("%d is greater than the no. of "
					"nodes in list", n);
				return;
			}
			ref_ptr = ref_ptr->next;
			count++;
		} /* End of while*/

		while (ref_ptr != NULL)
		{
			main_ptr = main_ptr->next;
			ref_ptr = ref_ptr->next;
		}
		printf("Node no. %d from last is %d ",
			n, main_ptr->data);
	}
}

// way 2 recusive
void printNthFromLastRec(struct Node *head, int n)
{
	static int i = 0;
	if (head == NULL) return;
	//	printf("%d,", head->data);
		printNthFromLastRec(head->next, n);
		if(++i == n)
		printf("itis %d,", head->data);

}
// output frome recusive
//35===,==15===,==4===,==20===,==the 3 th elem from end of list is : itis 15,
//
// Way 3
/* Function to get the nth node from the last of a linked list*/
void printNthFromLastway3(struct Node *head, int n)
{
	struct Node *main_ptr = head;
	struct Node *ref_ptr = head;

	int count = 0;
	if (head != NULL)
	{
		while (count < n)    // better save one time travel , 
		{
			if (ref_ptr == NULL)
			{
				printf("%d is greater than the no. of "
					"nodes in list", n);
				return;
			}
			ref_ptr = ref_ptr->next;
			count++;
		} /* End of while*/

		while (ref_ptr != NULL)
		{
			main_ptr = main_ptr->next;
			ref_ptr = ref_ptr->next;
		}
		printf("Node no. %d from last is %d ",
			n, main_ptr->data);
	}
}
void printNthFromLastway3Mine(struct Node *head, int n)
{
	struct Node *main_ptr = head;
	struct Node *ref_ptr = head;
	int cnt = n;
	int size = 0;
	/*while (head->next != NULL)  // this travel can be saved by if(ref ==NULL)
	{
		head = head->next;
		size++;
	} */  //can be saved
	//if (n > size) return;
	for (cnt = 0; cnt < n; cnt++)
	{ 
		if (ref_ptr == NULL) return;
		ref_ptr = ref_ptr->next;
	}
	while (ref_ptr != NULL)
	{
		ref_ptr = ref_ptr->next;
		main_ptr = main_ptr->next;
	}

	printf("%d",main_ptr->data);
	
}

void printlist(Node * head)
{
	//Node * ptr = head;
	if (head ==NULL) return;
	printf("%d,", head->data);
	printlist(head->next);
}



void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node * head = NULL;
	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 35);
 	printlist(head);
	int n = 3;
	printf("the %d th elem from end of list is : ",3);

	printNthFromLastRec(head, n);
	printNthFromLastway3Mine(head, n);

	//printNthFromLast(head, 2);

	getchar();
    return 0;
}


