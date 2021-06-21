#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
	int value;
	struct linked_list *next;
} List;

int main()
{
	List node1; 
	List node2;
	List node3;

	node1.value = 1;
	node1.next = node2;

	node2.value = 2;
	node2.next = &node3;

	node3.value = 3;
	node3.next = NULL;

	printf("%d", node1.next->value);
	printf("%d", node1.value);

	return (0);
}
