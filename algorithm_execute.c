#include <stdlib.h>
#include "push_swap.h"

static void execute_ra_moves(t_list *stack_a, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        ra(stack_a);
        i++;
    }
}

static void execute_rb_moves(t_list *stack_b, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        rb(stack_b);
        i++;
    }
}

static void execute_rr_moves(t_list *stack_a, t_list *stack_b, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        rr(stack_a, stack_b);
        i++;
    }
}

static void execute_reverse_moves(t_list *a, t_list *b, t_node *node)
{
    int i;

    i = 0;
    while (i < node->rra_cost)
    {
        rra(a);
        i++;
    }
    i = 0;
    while (i < node->rrb_cost)
    {
        rrb(b);
        i++;
    }
    i = 0;
    while (i < node->rrr_cost)
    {
        rrr(a, b);
        i++;
    }
}

void execute_moves(t_list *stack_a, t_list *stack_b, t_node *node)
{
    if (!stack_a || !stack_b || stack_b->size == 0)
        return;
    execute_ra_moves(stack_a, node->ra_cost);
    execute_rb_moves(stack_b, node->rb_cost);
    execute_reverse_moves(stack_a, stack_b, node);
    execute_rr_moves(stack_a, stack_b, node->rr_cost);
    pa(stack_a, stack_b);
}
