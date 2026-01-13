#include <stdio.h>
#include "push_swap.h"
#include "ft_printf.h"

void print_sorted_values(t_list *stack)
{
    t_node *current;
    int count;

    if (!stack || stack->size == 0)
        return;
    ft_printf("\nSorted values: ");
    current = stack->head;
    count = 0;
    while (current != NULL)
    {
        ft_printf("%d", current->value);
        if (current->next != NULL)
            ft_printf(", ");
        current = current->next;
        count++;
        if (count % 20 == 0)
            ft_printf("\n               ");
    }
    ft_printf("\n");
}

static void write_elements(FILE *file, t_list *stack)
{
    t_node *current;
    int count;

    current = stack->head;
    count = 0;
    while (current != NULL)
    {
        fprintf(file, "%d", current->value);
        if (current->next != NULL)
            fprintf(file, ", ");
        current = current->next;
        count++;
        if (count % 10 == 0 && current != NULL)
            fprintf(file, "\n");
    }
}

void write_stack_to_file(t_list *stack, const char *filename)
{
    FILE *file;

    file = fopen(filename, "w");
    if (!file)
    {
        ft_printf("Error: Could not create file %s\n", filename);
        return;
    }
    if (!stack || stack->size == 0)
    {
        fclose(file);
        return;
    }
    fprintf(file, "Sorted Stack A (%d elements):\n\n", stack->size);
    write_elements(file, stack);
    fprintf(file, "\n\n--- END ---\n");
    fclose(file);
    ft_printf("✓ Stack saved to file: %s\n", filename);
}
