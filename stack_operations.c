#include <stdlib.h>
#include "push_swap.h"

void initialise_stack(t_list *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

static void init_node_costs(t_node *node)
{
    node->index = -1;
    node->target = -1;
    node->total_cost = 0;
    node->ra_cost = 0;
    node->rb_cost = 0;
    node->rr_cost = 0;
    node->rra_cost = 0;
    node->rrb_cost = 0;
    node->rrr_cost = 0;
}

t_node *create_node(int num)
{
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = num;
    init_node_costs(new_node);
    new_node->next = NULL;
    new_node->prv = NULL;
    return (new_node);
}

void append_to_stack(t_list *stack, t_node *new_node)
{
    if (!stack || !new_node)
        return;
    if (stack->head == NULL)
    {
        stack->head = new_node;
        stack->tail = new_node;
    }
    else
    {
        stack->tail->next = new_node;
        new_node->prv = stack->tail;
        stack->tail = new_node;
    }
    stack->size++;
}

void fill_stack_a(t_list *stack, int *arr, int size)
{
    int i;
    t_node *new_node;

    if (!stack || !arr || size <= 0)
        return;
    i = 0;
    while (i < size)
    {
        new_node = create_node(arr[i]);
        if (!new_node)
            return;
        append_to_stack(stack, new_node);
        i++;
    }
}

void free_stack(t_list *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;
    current = stack->head;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}
