#include "push_swap.h"
#include "ft_printf.h"

extern int g_move_count;

void push_to_stack(t_list *source, t_list *destination)
{
    t_node *current_node;

    if (!source || !destination || !source->head)
        return;
    current_node = source->head;
    source->head = current_node->next;
    if (source->head != NULL)
        source->head->prv = NULL;
    else
        source->tail = NULL;
    current_node->prv = NULL;
    current_node->next = NULL;
    if (destination->head == NULL)
    {
        destination->head = current_node;
        destination->tail = current_node;
    }
    else
    {
        current_node->next = destination->head;
        destination->head->prv = current_node;
        destination->head = current_node;
    }
    source->size--;
    destination->size++;
}

void pb(t_list *stack_a, t_list *stack_b)
{
    push_to_stack(stack_a, stack_b);
    ft_printf("pb\n");
    g_move_count++;
}

void pa(t_list *stack_a, t_list *stack_b)
{
    push_to_stack(stack_b, stack_a);
    ft_printf("pa\n");
    g_move_count++;
}

void fill_stack_b(t_list *stack_a, t_list *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    while (stack_a->size > 3)
        pb(stack_a, stack_b);
}
