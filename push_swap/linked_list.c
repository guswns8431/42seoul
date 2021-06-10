#include <stdio.h>
#include <stdlib.h>


typedef struct list{
	int data;
	struct list *next;
} l_list;

void insertnode(l_list *node, int val)
{
	l_list *newnode = (l_list*)malloc(sizeof(l_list));

	node->next = newnode;
	newnode->data = val;
	newnode->next = NULL;
}

int main(void)
{
	l_list *head = malloc(sizeof(l_list));

	l_list *node1 = malloc(sizeof(l_list));
	head->next = node1;
	node1->data = 1;

	insertnode(node1, 2);
	insertnode(node1, 3);
	printf("%d %d %d", head->next->data, head->next->next->data, head->next->next->next->data);
	return (0);
}
