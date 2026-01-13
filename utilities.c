#include "push_swap.h"
#include "ft_printf.h"

t_node *find_min_node_value(t_list *stack)
{
    t_node *current_node;
    t_node *min_value_node;

    if (!stack || stack->size == 0)
        return (NULL);
    min_value_node = stack->head;
    current_node = min_value_node->next;
    while (current_node != NULL)
    {
        if (min_value_node->value > current_node->value)
            min_value_node = current_node;
        current_node = current_node->next;
    }
    return (min_value_node);
}

t_node *find_min_node_cost(t_list *stack)
{
    t_node *current_node;
    t_node *min_cost_node;

    if (!stack || stack->size == 0)
        return (NULL);
    min_cost_node = stack->head;
    current_node = min_cost_node->next;
    while (current_node != NULL)
    {
        if (current_node->total_cost < min_cost_node->total_cost)
            min_cost_node = current_node;
        current_node = current_node->next;
    }
    return (min_cost_node);
}

int is_sorted(t_list *stack)
{
    t_node *current;

    if (!stack || stack->size == 0)
        return (1);
    current = stack->head;
    while (current->next != NULL)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

static void print_node_info(t_node *node)
{
    ft_printf("value = %d, index = %d, target = %d, ",
              node->value, node->index, node->target);
    ft_printf("total_cost = %d,\n", node->total_cost);
    ft_printf("ra_cost = %d, rb_cost = %d, rr_cost = %d, ",
              node->ra_cost, node->rb_cost, node->rr_cost);
    ft_printf("rra_cost = %d, rrb_cost = %d, rrr_cost = %d\n",
              node->rra_cost, node->rrb_cost, node->rrr_cost);
}

void print_stack(t_list *stack, char letter)
{
    t_node *current_node;

    if (!stack || stack->head == NULL)
    {
        ft_printf("Stack %c is empty\n", letter);
        return;
    }
    ft_printf("Stack %c\n", letter);
    current_node = stack->head;
    while (current_node != NULL)
    {
        print_node_info(current_node);
        current_node = current_node->next;
    }
}
