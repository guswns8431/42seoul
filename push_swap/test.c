#include "push_swap.h"

int main(void)
{
	t_stack *stack;

	create_stack(&stack);
	insert_node(&stack, 1);
	insert_node(&stack, 2);
	insert_node(&stack, 3);

	t_node *cur = stack->top;
	while (cur->prev != NULL)
	{
		cur = cur->prev;
		printf("%d\n", cur->val);

	}

	delete_node(&stack);

	printf("%d", stack->top->val);
	printf("%d", stack->top->prev->val);
	return (0);
}
