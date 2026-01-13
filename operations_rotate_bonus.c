/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stddef.h>

static void rotate_stack(t_list *stack)
{
    t_node *current_node;

    if (!stack || stack->size < 2)
        return;
    current_node = stack->head;
    stack->head = current_node->next;
    stack->head->prv = NULL;
    current_node->prv = stack->tail;
    stack->tail->next = current_node;
    stack->tail = current_node;
    stack->tail->next = NULL;
}

void ra_silent(t_list *stack_a)
{
    rotate_stack(stack_a);
}

void rb_silent(t_list *stack_b)
{
    rotate_stack(stack_b);
}

void rr_silent(t_list *stack_a, t_list *stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
}
