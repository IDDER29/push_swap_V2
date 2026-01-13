#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static long long parse_digits(const char **str, int *error)
{
    long long result;
    long long prev;

    result = 0;
    while (**str >= '0' && **str <= '9')
    {
        prev = result;
        result = result * 10 + (*(*str)++ - '0');
        if (result / 10 != prev || result < 0)
        {
            *error = 1;
            return (0);
        }
    }
    return (result);
}

int ft_atoi_check(const char *str, int *error)
{
    int sign;
    long long result;

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
    result = parse_digits(&str, error);
    if (*error)
        return (0);
    if (sign == 1 && result > INT_MAX)
        *error = 1;
    if (sign == -1 && result > 2147483648LL)
        *error = 1;
    if (*str != '\0')
        *error = 1;
    return ((int)(result * sign));
}

int check_duplicates(int *arr, int size)
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
