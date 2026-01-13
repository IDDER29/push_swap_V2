#include "ft_printf.h"
#include "push_swap.h"

static void	push_to_stack(t_list *source, t_list *destination)
{
	t_node	*node;

	if (!source || !destination || !source->head)
		return ;
	node = source->head;
	source->head = node->next;
	if (source->head != NULL)
		source->head->prv = NULL;
	else
		source->tail = NULL;
	node->prv = NULL;
	node->next = NULL;
	if (destination->head == NULL)
	{
		destination->head = node;
		destination->tail = node;
	}
	else
	{
		node->next = destination->head;
		destination->head->prv = node;
		destination->head = node;
	}
	source->size--;
	destination->size++;
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	push_to_stack(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	push_to_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	fill_stack_b(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	while (stack_a->size > 3)
		pb(stack_a, stack_b);
}
