#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct node
{
    int value;
    int index;
    int target;
    int total_cost;
    int ra_cost;
    int rb_cost;
    int rr_cost;
    int rra_cost;
    int rrb_cost;
    int rrr_cost;
    struct node *next;
    struct node *prv;
} t_node;

typedef struct list
{
    t_node *head;
    t_node *tail;
    int size;
} t_list;

/* stack_operations.c */
void initialise_stack(t_list *stack);
t_node *create_node(int num);
void append_to_stack(t_list *stack, t_node *new_node);
void fill_stack_a(t_list *stack, int *arr, int size);
void free_stack(t_list *stack);

/* push_swap_operations.c */
void pb(t_list *stack_a, t_list *stack_b);
void pa(t_list *stack_a, t_list *stack_b);
void fill_stack_b(t_list *stack_a, t_list *stack_b);
void sa(t_list *stack_a);
void sb(t_list *stack_b);
void ss(t_list *stack_a, t_list *stack_b);

/* rotate_operations.c */
void ra(t_list *stack_a);
void rb(t_list *stack_b);
void rr(t_list *stack_a, t_list *stack_b);
void rra(t_list *stack_a);
void rrb(t_list *stack_b);
void rrr(t_list *stack_a, t_list *stack_b);

/* algorithm.c */
void sort_three(t_list *stack);
void assign_indexes(t_list *stack);
void assign_target(t_list *source, t_list *destination);
int min(int a, int b);
int calc_node_cost(t_node *node, t_list *src, t_list *dest);
void calculate_cost(t_list *source, t_list *destination);
void execute_moves(t_list *stack_a, t_list *stack_b, t_node *node);
void init_stack_cost(t_list *stack);

/* utilities.c */
t_node *find_min_node_value(t_list *stack);
t_node *find_min_node_cost(t_list *stack);
int is_sorted(t_list *stack);
char *ft_strncpy(char *dest, char *src, int n);

/* input_validation.c */
int ft_isspace(char c);
int ft_atoi_check(const char *str, int *error);
int check_duplicates(int *arr, int size);

/* input_parse_utils.c */
int parse_single_arg(char *arg, int *error);
int count_numbers(char *str);
char *skip_spaces(char *str);
int get_number_length(char *str);
int count_total_numbers(int argc, char **argv);

/* input_parse_string.c */
int *parse_string(char *str, int *size);

/* input_parse_args.c */
int *parse_all_args(int argc, char **argv, int *size);

/* push_swap_main.c */
void push_swap(int *data, int size);

#endif