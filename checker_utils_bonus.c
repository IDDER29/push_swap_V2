/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	execute_push_swap(char *line, t_list *a, t_list *b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_silent(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_silent(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_silent(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_silent(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_silent(a, b);
	else
		return (0);
	return (1);
}

static int	execute_rotate(char *line, t_list *a, t_list *b)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra_silent(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_silent(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_silent(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_silent(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_silent(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_silent(a, b);
	else
		return (0);
	return (1);
}

static void	trim_line_ending(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\r' || line[i] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = '\0';
			return ;
		}
		i++;
	}
}

int	execute_instruction(char *line, t_list *stack_a, t_list *stack_b)
{
	if (!line)
		return (0);
	trim_line_ending(line);
	if (line[0] == '\n')
		return (1);
	if (execute_push_swap(line, stack_a, stack_b))
		return (1);
	if (execute_rotate(line, stack_a, stack_b))
		return (1);
	return (0);
}
