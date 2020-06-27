3->2->1->inserting
3->9->2->8->1->Appending
3->9->2->8->1->100->


===problem of if not prepare new_node, hook it too early

9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9->9

nsertAfter(Node* pre, int new_data)
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
	pre->next = new_node;
	// 5  new node's next = pre's next
//	new_node->next = pre->next;
	//4  new node's next = pre's next   prepare   ===== cause ->9 loop
	new_node->next = pre->next;
// 5 pre 's next = newnode --- connect
	//pre->next = new_node;
}