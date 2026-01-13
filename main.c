#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int g_move_count = 0;

static int parse_single_arg(char *arg, int *error)
{
    *error = 0;
    return (ft_atoi_check(arg, error));
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
        arr[i] = parse_single_arg(argv[i + 1], &error);
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