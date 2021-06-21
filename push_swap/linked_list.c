#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
	int value;
	struct linked_list *next;
} List;

int main()
{
	List *node1 = malloc(sizeof(struct linked_list));
	List *node2 = malloc(sizeof(struct linked_list));
	List *node3 = malloc(sizeof(struct linked_list));

	node1->value = 1;
	node1->next = node2;

	node2->value = 2;
	node2->next = node3;

	node3->value = 3;
	node3->next = NULL;

	printf("%d %d %d\n", node1->value, node2->value, node3->value);
	printf("%d %d %d\n", node1->value, node1->next->value, node1->next->next->value);
	return (0);
}

