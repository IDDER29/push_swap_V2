/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stddef.h>

static void swap_list(t_list *stack)
{
    t_node *first_node;
    t_node *second_node;

    if (!stack || stack->size < 2)
        return;
    first_node = stack->head;
    second_node = stack->head->next;
    first_node->prv = second_node;
    first_node->next = second_node->next;
    second_node->prv = NULL;
    second_node->next = first_node;
    stack->head = second_node;
    if (stack->size == 2)
        stack->tail = first_node;
    else
        first_node->next->prv = first_node;
}

void sa_silent(t_list *stack_a)
{
    if (!stack_a)
        return;
    swap_list(stack_a);
}

void sb_silent(t_list *stack_b)
{
    if (!stack_b)
        return;
    swap_list(stack_b);
}

void ss_silent(t_list *stack_a, t_list *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    swap_list(stack_a);
    swap_list(stack_b);
}
