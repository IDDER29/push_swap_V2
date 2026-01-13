/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: developer <developer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:00 by developer         #+#    #+#             */
/*   Updated: 2026/01/13 00:00:00 by developer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int main(int argc, char **argv)
{
    int *data;
    int size;

    if (argc < 2)
        return (0);
    data = parse_all_args(argc, argv, &size);
    if (!data)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    push_swap(data, size);
    free(data);
    return (0);
}