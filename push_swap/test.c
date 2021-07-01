#include "push_swap.h"

int main(void)
{
	t_stack *a;
	t_stack *b;

	create_stack(&a);
	create_stack(&b);
	insert_node(&a, 1);
	insert_node(&a, 2);
	insert_node(&a, 3);

	insert_node(&b, 4);
	insert_node(&b, 5);
	insert_node(&b, 6);

	//printf("%d", b->top->val);
	//printf("%d", b->top->prev->val);
	push(&a, &b, 'b');
	push(&a, &b, 'b');

	t_node *cur = a->top;
	printf("%d", cur->val);
	while (cur->prev != NULL)
	{
		printf("%d\n", cur->val);
		cur = cur->prev;
		if (cur->prev == NULL)
			printf("%d\n", cur->val);
	}

	//printf("%d", b->top->val);
	//printf("%d", b->top->prev->val);
	return (0);
}
