/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

typedef struct node
{
	int			value;
	int			index;
	int			target;
	int			total_cost;
	int			ra_cost;
	int			rb_cost;
	int			rr_cost;
	int			rra_cost;
	int			rrb_cost;
	int			rrr_cost;
	struct node	*next;
	struct node	*prv;
}				t_node;

typedef struct list
{
	t_node		*head;
	t_node		*tail;
	int			size;
}				t_list;

/* stack_operations.c */
void			initialise_stack(t_list *stack);
t_node			*create_node(int num);
void			append_to_stack(t_list *stack, t_node *new_node);
void			fill_stack_a(t_list *stack, int *arr, int size);
void			free_stack(t_list *stack);

/* input_validation.c */
int				ft_isspace(char c);
int				ft_atoi_check(const char *str, int *error);
int				check_duplicates(int *arr, int size);

/* input_parse_utils.c */
int				parse_single_arg(char *arg, int *error);
int				count_numbers(char *str);
char			*skip_spaces(char *str);
int				get_number_length(char *str);
int				count_total_numbers(int argc, char **argv);

/* input_parse_string.c */
int				*parse_string(char *str, int *size);

/* input_parse_args.c */
int				*parse_all_args(int argc, char **argv, int *size);

/* utilities.c */
t_node			*find_min_node_value(t_list *stack);
int				is_sorted(t_list *stack);

/* operations_bonus.c */
void			pa_silent(t_list *stack_a, t_list *stack_b);
void			pb_silent(t_list *stack_a, t_list *stack_b);
void			sa_silent(t_list *stack_a);
void			sb_silent(t_list *stack_b);
void			ss_silent(t_list *stack_a, t_list *stack_b);
void			ra_silent(t_list *stack_a);
void			rb_silent(t_list *stack_b);
void			rr_silent(t_list *stack_a, t_list *stack_b);
void			rra_silent(t_list *stack_a);
void			rrb_silent(t_list *stack_b);
void			rrr_silent(t_list *stack_a, t_list *stack_b);

/* checker_utils_bonus.c */
char			*get_next_line(int fd);
int				execute_instruction(char *line, t_list *stack_a,
					t_list *stack_b);
int				ft_strcmp(const char *s1, const char *s2);

#endif
