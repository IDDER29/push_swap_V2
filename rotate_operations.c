#include "ft_printf.h"
#include "push_swap.h"

static void	rotate_stack(t_list *stack)
{
	t_node	*current_node;

	if (!stack || stack->size < 2)
		return ;
	current_node = stack->head;
	stack->head = current_node->next;
	stack->head->prv = NULL;
	current_node->prv = stack->tail;
	stack->tail->next = current_node;
	stack->tail = current_node;
	stack->tail->next = NULL;
}

void	ra(t_list *stack_a)
{
	rotate_stack(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list *stack_b)
{
	rotate_stack(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_printf("rr\n");
}
