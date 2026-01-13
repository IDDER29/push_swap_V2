#include "push_swap.h"
#include "ft_printf.h"

void sort_three(t_list *stack)
{
    int a;
    int b;
    int c;

    if (!stack || stack->size < 2)
        return;
    a = stack->head->value;
    b = stack->head->next->value;
    c = stack->tail->value;
    if (a > b && a > c)
        ra(stack);
    else if (b > a && b > c)
        rra(stack);
    if (stack->head->value > stack->head->next->value)
        sa(stack);
}

void assign_indexes(t_list *stack)
{
    int i;
    t_node *current_node;

    if (!stack)
        return;
    i = 0;
    current_node = stack->head;
    while (i < stack->size)
    {
        current_node->index = i;
        current_node = current_node->next;
        i++;
    }
}

int min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

void init_stack_cost(t_list *stack)
{
    t_node *current_node;

    if (!stack || stack->size == 0)
        return;
    current_node = stack->head;
    while (current_node != NULL)
    {
        current_node->ra_cost = 0;
        current_node->rb_cost = 0;
        current_node->rr_cost = 0;
        current_node->rra_cost = 0;
        current_node->rrb_cost = 0;
        current_node->rrr_cost = 0;
        current_node->total_cost = 0;
        current_node = current_node->next;
    }
}
