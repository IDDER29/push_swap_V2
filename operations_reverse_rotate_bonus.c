/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stddef.h>

static void reverse_rotate_stack(t_list *stack)
{
    t_node *current_node;

    if (!stack || stack->size < 2)
        return;
    current_node = stack->tail;
    stack->tail = current_node->prv;
    current_node->prv = NULL;
    current_node->next = stack->head;
    stack->head->prv = current_node;
    stack->head = current_node;
    stack->tail->next = NULL;
}

void rra_silent(t_list *stack_a)
{
    if (!stack_a)
        return;
    reverse_rotate_stack(stack_a);
}

void rrb_silent(t_list *stack_b)
{
    if (!stack_b)
        return;
    reverse_rotate_stack(stack_b);
}

void rrr_silent(t_list *stack_a, t_list *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    reverse_rotate_stack(stack_a);
    reverse_rotate_stack(stack_b);
}
