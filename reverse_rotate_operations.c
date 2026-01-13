#include "ft_printf.h"
#include "push_swap.h"

static void	reverse_rotate_stack(t_list *stack)
{
	t_node	*current_node;

	if (!stack || stack->size < 2)
		return ;
	current_node = stack->tail;
	stack->tail = current_node->prv;
	current_node->prv = NULL;
	current_node->next = stack->head;
	stack->head->prv = current_node;
	stack->head = current_node;
	stack->tail->next = NULL;
}

void	rra(t_list *stack_a)
{
	if (!stack_a)
		return ;
	reverse_rotate_stack(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list *stack_b)
{
	if (!stack_b)
		return ;
	reverse_rotate_stack(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_printf("rrr\n");
}
