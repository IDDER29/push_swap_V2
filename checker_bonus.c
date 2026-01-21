/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
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

static void	free_all(t_list *stack_a, t_list *stack_b, char *line)
{
	if (line)
		free(line);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}

static void	error_exit(t_list *stack_a, t_list *stack_b, char *line)
{
	char	*temp;

	temp = get_next_line(-1);
	free(temp);
	free_all(stack_a, stack_b, line);
	write(2, "Error\n", 6);
	exit(1);
}

static void	print_result(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		*data;
	int		size;
	t_list	stack_a;
	t_list	stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	data = parse_all_args(argc, argv, &size);
	if (!data)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	initialise_stack(&stack_a);
	initialise_stack(&stack_b);
	fill_stack_a(&stack_a, data, size);
	free(data);
	line = get_next_line(0);
	while (line)
	{
		if (!execute_instruction(line, &stack_a, &stack_b))
			error_exit(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	print_result(&stack_a, &stack_b);
	free_all(&stack_a, &stack_b, NULL);
	line = get_next_line(-1);
	free(line);
	return (0);
}
