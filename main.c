#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"
#include "ft_printf.h"

int g_move_count = 0;

static int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static int ft_atoi_check(const char *str, int *error)
{
    long result;
    int sign;

    result = 0;
    sign = 1;
    while (ft_isspace(*str))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    if (!(*str >= '0' && *str <= '9'))
    {
        *error = 1;
        return (0);
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str++ - '0');
        if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
        {
            *error = 1;
            return (0);
        }
    }
    if (*str != '\0')
        *error = 1;
    return ((int)(result * sign));
}

static int check_duplicates(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] == arr[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int *parse_arguments(int argc, char **argv, int *size)
{
    int *arr;
    int i;
    int error;

    *size = argc - 1;
    arr = malloc(sizeof(int) * (*size));
    if (!arr)
        return (NULL);
    i = 0;
    while (i < *size)
    {
        error = 0;
        arr[i] = ft_atoi_check(argv[i + 1], &error);
        if (error)
        {
            free(arr);
            return (NULL);
        }
        i++;
    }
    if (check_duplicates(arr, *size))
    {
        free(arr);
        return (NULL);
    }
    return (arr);
}

static void push_swap(int *data, int size)
{
    t_list stack_a;
    t_list stack_b;
    t_node *min_node;
    int ra_cost;
    int rra_cost;
    int i;

    initialise_stack(&stack_a);
    initialise_stack(&stack_b);
    fill_stack_a(&stack_a, data, size);
    if (is_sorted(&stack_a))
        return;
    if (size == 2)
    {
        sa(&stack_a);
        return;
    }
    if (size == 3)
    {
        sort_three(&stack_a);
        return;
    }
    fill_stack_b(&stack_a, &stack_b);
    sort_three(&stack_a);
    while (stack_b.size > 0)
    {
        init_stack_cost(&stack_b);
        assign_indexes(&stack_a);
        assign_indexes(&stack_b);
        assign_target(&stack_b, &stack_a);
        calculate_cost(&stack_b, &stack_a);
        min_node = find_min_node_cost(&stack_b);
        execute_moves(&stack_a, &stack_b, min_node);
    }
    if (!is_sorted(&stack_a))
    {
        assign_indexes(&stack_a);
        min_node = find_min_node_value(&stack_a);
        ra_cost = min_node->index;
        rra_cost = stack_a.size - ra_cost;
        i = 0;
        if (ra_cost < rra_cost)
        {
            while (i++ < ra_cost)
                ra(&stack_a);
        }
        else
        {
            while (i++ < rra_cost)
                rra(&stack_a);
        }
    }
    free_stack(&stack_a);
    free_stack(&stack_b);
}

int main(int argc, char **argv)
{
    int *data;
    int size;

    if (argc < 2)
        return (0);
    data = parse_arguments(argc, argv, &size);
    if (!data)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    push_swap(data, size);
    free(data);
    return (0);
}