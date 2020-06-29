
// linklist.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
// A linked list node 

struct Node
{
	int data;
	struct Node *next;
};


typedef struct Node Node;
#if 0
// Function to skip M nodes and then delete N nodes of the linked list. 
void skipMdeleteN(struct Node  *head, int M, int N) 
{ 
    struct Node *curr = head, *t; 
    int count; 
  
    // The main loop that traverses through the whole list 
    while (curr) 
    { 
        // Skip M nodes 
        for (count = 1; count<M && curr!= NULL; count++) 
            curr = curr->next; 
  
        // If we reached end of list, then return 
        if (curr == NULL) 
            return; 
  
        // Start from next node and delete N nodes 
        t = curr->next; 
        for (count = 1; count<=N && t!= NULL; count++) 
        { 
            struct Node *temp = t; 
            t = t->next; 
            free(temp); 
        } 
        curr->next = t; // Link the previous list with remaining nodes 
  
        // Set current pointer for next iteration 
        curr = t; 
    } 
} 
  
#endif


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
		// 4  new node's next = pre's next
	new_node->next = pre->next;
	//  new node's next = pre's next   prepare   ===== cause ->9 loop
	//new_node->next = pre->next;
// 5 pre 's next = newnode --- connect
	pre->next = new_node;
}
// get nth elemt
#if 0
int getNth(Node * head, int n)
{
 //Node * curr = head;
	int i = 0 , retval;
	//while(head->next !=0)  // bug cant get last elem
	while (head !=NULL)
	{
	  if(i ==n)
	    {
		retval = head->data;
		return retval;
		}
		i++;
		head = head->next;
    }
	printf("asking a noexit val\n");
	//return head->data;
}
#endif
// delet a linklist
/*
void deleteList(Node ** headref)
{
	Node * tmp;
	Node * curr = *headref;
	// travel list free each next pointer
	while( curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*headref = NULL;
}

*/


void free_list(Node *pHead)
{
	Node *pNode = pHead, *pNext;

	while (NULL != pNode)
	{
		pNext = pNode->next;
		free(pNode);
		pNode = pNext;
	}

}

/* Function to delete the entire linked list */
void deleteList(struct Node** head_ref)
{
	/* deref head_ref to get the real head */
	struct Node* current = *head_ref;
	struct Node* next;

	while (current != NULL)
	{
		next = current;
		 current = current->next;		
		free(current);			
	}

	/* deref head_ref to affect the real head back
	in the caller. */
	*head_ref = NULL;
}

// find the middle of a list
int getMiddle(Node * head)
{
	Node * fast = head;
	Node * slow = head;
	if (head != NULL)
	{
		while (fast !=NULL && fast->next != NULL )
		{
			fast = fast->next->next;
			slow = slow->next;

		}
		return slow->data; 
	}
}



int getNth(struct Node* head,
	int index)
{

	struct Node* current = head;

	// the index of the  
	// node we're currently 
	// looking at 
	int count = 0;
	while (current != NULL)
	{
		if (count == index)
			return(current->data);
		count++;
		current = current->next;
	}

	/* if we get to this line,
	the caller was asking
	for a non-existent element
	so we assert fail */
	//assert(0);
}

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
// count occuerene for a key
int count(struct Node* head, int key)
{
	//add your code here
	int  cnt = 0;
	struct Node * curr = head;
	while (curr != NULL)
	{
		if (curr->data == key)
		{
			cnt++;
		}
		curr = curr->next;
	}
	// printf("cnt%d\n",cnt);
	return cnt;
}

bool search(Node * head, int key)
{
	// base case
	if (head == NULL) return false;
	if (head->data == key) return true;
     return	search(head->next, key);
	
}

// fun to sort lint 0s. 1s and 2s
void sortList(Node *head)
{
	int count[3] = { 0,0,0 };
	Node *ptr = head;
	// save totol 0s to count[0]...
	while (ptr != NULL) 

	{ 
		// avoid statch smash
		assert(ptr->data <3);
		count[ptr->data] +=1 ;
		ptr = ptr->next;
	}
	int i = 0;
	ptr = head; // reset ptr to head
	// fill the list with 0, till count[0] >0
	while (ptr != NULL)
	{
		// if done with 1st elme, move to 2nd by ++i
		if (count[i] == 0)
			i++;
		else
		{
			ptr->data = i;
			count[i]--;
			ptr = ptr->next;
		}
	}

}
//output: //before //1->1->0->1->2->0-> //after //0->0->1->1->1->2->  
//Delete N nodes after M nodes of a linked list | GeeksforGeeks
//https://www.youtube.com/watch?v=PpY_C_NSNwk&list=PLqM7alHXFySH41ZxzrPNj2pAYPOI8ITe7&index=2

  void deleteNafterM(Node * head, int m, int n) {
	Node *ptr = head;
	Node * t;
	int cnt;
	while (ptr != NULL) // out loop for all nodes
	{
		//skip M nodes , until find new ptr

		for (cnt=1; cnt<m && ptr!=NULL; cnt ++)
		{
		ptr = ptr->next;
		}

			printf(" ptr nowis %d\n", ptr->data);
		if (ptr == NULL) return; // reach end of list
		// start form next node and del n nodes	
		t = ptr ->next;		 

		//	printf(" ptr nowis %d\n", t->data);
		for (cnt = 1; cnt <=n && t != NULL; cnt++)
		{
			printf(" in 2nd loop\n");

			Node * tmp = t;  // save pre
			// ptr need to del unlink ptr
			t = t->next;   // move forword
			free(tmp);
		}
		 // link pre with remining nodes
		ptr ->next = t;  //ptrnew= ptr->next

 //             printf ("*ptr =%d\n", ptr->data);	

		//set curnt for next iteration
        	ptr = t;
	}
	  // re set ptr to new start poing
printf ("*ptr =%d\n", ptr->data);	
}

int main()
{	
	
	Node * head =NULL;
	push(&head, 0);	
	push(&head, 2);
	push(&head, 1);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	//printlist(head);
	printf("before\n");
//	printlist(head);
//	printf("after sorting\n");
	sortList(head);
	printlist(head);
	int n =1, m =3;
	printf("after del %d nodes after %d nodes\n, ", n, m);
	deleteNafterM(head, n, m);
       // skipMdeleteN(head,m,n);
	printlist(head);

#if 0
	printf("inserting\n");
	insertAfter(head->next, 8);
	insertAfter(head, 9);
	printlist(head);
	printf("Appending\n");
	append(&head, 120);
	printlist(head);
	int n =5;
	printf("getnth  elem %dth,--> %d", n, getNth(head, n));
	printf("get middle element %d,", getMiddle(head));
	//deleteList(&head);
	//free_list(head);
	//int key = 9;
	printf("it has %d -%d\n",count(head, 9) ,9);
	printlist(head);
	printf("search -%d\ return:%d \n ",  9 , search(head, 9));
#endif
	getchar();
    return 0;
}


