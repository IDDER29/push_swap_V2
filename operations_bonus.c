/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stddef.h>

static void	push_to_stack(t_list *source, t_list *destination)
{
	t_node	*node;

	if (!source || !destination || !source->head)
		return ;
	node = source->head;
	source->head = node->next;
	if (source->head != NULL)
		source->head->prv = NULL;
	else
		source->tail = NULL;
	node->prv = NULL;
	node->next = NULL;
	if (destination->head == NULL)
	{
		destination->head = node;
		destination->tail = node;
	}
	else
	{
		node->next = destination->head;
		destination->head->prv = node;
		destination->head = node;
	}
	source->size--;
	destination->size++;
}

void	pb_silent(t_list *stack_a, t_list *stack_b)
{
	push_to_stack(stack_a, stack_b);
}

void	pa_silent(t_list *stack_a, t_list *stack_b)
{
	push_to_stack(stack_b, stack_a);
}
