#include "ft_printf.h"
#include "push_swap.h"

static void	swap_list(t_list *stack)
{
	t_node	*first_node;
	t_node	*second_node;

	if (!stack || stack->size < 2)
		return ;
	first_node = stack->head;
	second_node = stack->head->next;
	first_node->prv = second_node;
	first_node->next = second_node->next;
	second_node->prv = NULL;
	second_node->next = first_node;
	stack->head = second_node;
	if (stack->size == 2)
		stack->tail = first_node;
	else
		first_node->next->prv = first_node;
}

void	sa(t_list *stack_a)
{
	if (!stack_a)
		return ;
	swap_list(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	if (!stack_b)
		return ;
	swap_list(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap_list(stack_a);
	swap_list(stack_b);
	ft_printf("ss\n");
}
