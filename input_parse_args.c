#include "push_swap.h"
#include <stdlib.h>

static void	copy_temp_array(int *arr, int *temp_arr, int *idx, int temp_size)
{
	int	j;

	j = 0;
	while (j < temp_size)
	{
		arr[*idx] = temp_arr[j];
		(*idx)++;
		j++;
	}
}

static int	handle_string_arg(char *arg, int *arr, int *idx)
{
	int	*temp_arr;
	int	temp_size;

	temp_arr = parse_string(arg, &temp_size);
	if (!temp_arr)
		return (0);
	copy_temp_array(arr, temp_arr, idx, temp_size);
	free(temp_arr);
	return (1);
}

static int	handle_single_arg(char *arg, int *arr, int *idx)
{
	int	error;

	arr[*idx] = parse_single_arg(arg, &error);
	if (error)
		return (0);
	(*idx)++;
	return (1);
}

static int	process_argument(char *arg, int *arr, int *idx)
{
	if (count_numbers(arg) > 1)
		return (handle_string_arg(arg, arr, idx));
	else
		return (handle_single_arg(arg, arr, idx));
}

int	*parse_all_args(int argc, char **argv, int *size)
{
	int	*arr;
	int	i;
	int	idx;

	*size = count_total_numbers(argc, argv);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		return (NULL);
	idx = 0;
	i = 1;
	while (i < argc)
	{
		if (!process_argument(argv[i], arr, &idx))
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
