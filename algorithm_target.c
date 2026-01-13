#include <stdlib.h>
#include "push_swap.h"

static t_node *find_target_node(t_node *src_node, t_list *dest)
{
    t_node *target;
    t_node *current_dest;

    target = NULL;
    current_dest = dest->head;
    while (current_dest != NULL)
    {
        if (src_node->value < current_dest->value)
        {
            if (target == NULL || current_dest->value < target->value)
                target = current_dest;
        }
        current_dest = current_dest->next;
    }
    if (target == NULL)
        target = find_min_node_value(dest);
    return (target);
}

void assign_target(t_list *source, t_list *destination)
{
    t_node *current_source;
    t_node *target_node;

    if (!source || !destination)
        return;
    if (source->size == 0 || destination->size == 0)
        return;
    current_source = source->head;
    while (current_source != NULL)
    {
        target_node = find_target_node(current_source, destination);
        current_source->target = target_node->index;
        current_source = current_source->next;
    }
}

void calculate_cost(t_list *source, t_list *destination)
{
    t_node *current_node;

    if (!source || !destination)
        return;
    if (source->size == 0 || destination->size == 0)
        return;
    current_node = source->head;
    while (current_node != NULL)
    {
        current_node->total_cost = calc_node_cost(current_node,
                                                  source, destination);
        current_node = current_node->next;
    }
}
