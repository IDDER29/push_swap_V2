#include <stdlib.h>
#include "push_swap.h"

static void handle_small_sort(t_list *stack_a, int size)
{
    if (size == 2)
        sa(stack_a);
    else if (size == 3)
        sort_three(stack_a);
}

static void final_rotation(t_list *stack_a)
{
    t_node *min_node;
    int ra_cost;
    int rra_cost;
    int i;

    assign_indexes(stack_a);
    min_node = find_min_node_value(stack_a);
    ra_cost = min_node->index;
    rra_cost = stack_a->size - ra_cost;
    i = 0;
    if (ra_cost < rra_cost)
    {
        while (i++ < ra_cost)
            ra(stack_a);
    }
    else
    {
        while (i++ < rra_cost)
            rra(stack_a);
    }
}

static void push_swap_large(t_list *stack_a, t_list *stack_b)
{
    t_node *min_node;

    fill_stack_b(stack_a, stack_b);
    sort_three(stack_a);
    while (stack_b->size > 0)
    {
        init_stack_cost(stack_b);
        assign_indexes(stack_a);
        assign_indexes(stack_b);
        assign_target(stack_b, stack_a);
        calculate_cost(stack_b, stack_a);
        min_node = find_min_node_cost(stack_b);
        execute_moves(stack_a, stack_b, min_node);
    }
    if (!is_sorted(stack_a))
        final_rotation(stack_a);
}

void push_swap(int *data, int size)
{
    t_list stack_a;
    t_list stack_b;

    initialise_stack(&stack_a);
    initialise_stack(&stack_b);
    fill_stack_a(&stack_a, data, size);
    if (is_sorted(&stack_a))
    {
        free_stack(&stack_a);
        return;
    }
    if (size <= 3)
    {
        handle_small_sort(&stack_a, size);
        free_stack(&stack_a);
        return;
    }
    push_swap_large(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
}
