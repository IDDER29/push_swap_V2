#include "push_swap.h"
#include <stdlib.h>

static int	*allocate_array(int size)
{
	int	*arr;

	arr = malloc(sizeof(int) * size);
	return (arr);
}

static char	*extract_number(char *str, int len)
{
	char	*num_str;

	num_str = malloc(len + 1);
	if (!num_str)
		return (NULL);
	ft_strncpy(num_str, str, len);
	num_str[len] = '\0';
	return (num_str);
}

static int	parse_and_add_number(char **str, int *arr, int i)
{
	char	*num_str;
	int		len;
	int		error;

	len = get_number_length(*str);
	num_str = extract_number(*str, len);
	if (!num_str)
		return (0);
	arr[i] = parse_single_arg(num_str, &error);
	free(num_str);
	if (error)
		return (0);
	*str += len;
	*str = skip_spaces(*str);
	return (1);
}

int	*parse_string(char *str, int *size)
{
	int	*arr;
	int	i;

	*size = count_numbers(str);
	if (*size == 0)
		return (NULL);
	arr = allocate_array(*size);
	if (!arr)
		return (NULL);
	i = 0;
	str = skip_spaces(str);
	while (*str && i < *size)
	{
		if (!parse_and_add_number(&str, arr, i))
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
