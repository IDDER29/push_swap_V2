#include "push_swap.h"
#include "ft_printf.h"

char *ft_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}

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
