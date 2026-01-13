#include <stdlib.h>
#include "push_swap.h"

int parse_single_arg(char *arg, int *error)
{
    *error = 0;
    return (ft_atoi_check(arg, error));
}

int count_numbers(char *str)
{
    int count;
    int in_number;

    count = 0;
    in_number = 0;
    while (*str)
    {
        if (ft_isspace(*str))
            in_number = 0;
        else if (!in_number)
        {
            in_number = 1;
            count++;
        }
        str++;
    }
    return (count);
}

char *skip_spaces(char *str)
{
    while (*str && ft_isspace(*str))
        str++;
    return (str);
}

int get_number_length(char *str)
{
    int len;

    len = 0;
    while (str[len] && !ft_isspace(str[len]))
        len++;
    return (len);
}

int count_total_numbers(int argc, char **argv)
{
    int total;
    int i;

    total = 0;
    i = 1;
    while (i < argc)
    {
        if (count_numbers(argv[i]) > 0)
            total += count_numbers(argv[i]);
        else
            total++;
        i++;
    }
    return (total);
}
