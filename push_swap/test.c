#include <stdio.h>
#include <stdlib.h>

struct NODE {
	struct NODE *next;
	int data;
};

int main()
{
	struct NODE head;
	struct NODE node1;
	head.next = &node1;
	node1.data = 1;
	
	struct NODE node2;
	node1.next = &node2;
	node2.data = 2;

	node2.next = NULL;

	struct NODE *curr = head.next;
	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	return (0);
}
