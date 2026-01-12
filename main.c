#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "ft_printf.h"

int g_move_count = 0;

void append_to_stack(t_list *stack, t_node *new_node)
{
    if (!stack || !new_node)
    {
        return;
    }

    if (stack->head == NULL)
    {
        stack->head = new_node;
        stack->tail = new_node;
    }
    else
    {
        stack->tail->next = new_node;
        new_node->prv = stack->tail;
        stack->tail = new_node;
    }
    stack->size++;
}

t_node *create_node(int num)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        return NULL;
    }
    new_node->value = num;
    new_node->index = -1;
    new_node->target = -1;
    new_node->total_cost = 0;
    new_node->ra_cost = 0;
    new_node->rb_cost = 0;
    new_node->rr_cost = 0;
    new_node->rra_cost = 0;
    new_node->rrb_cost = 0;
    new_node->rrr_cost = 0;
    new_node->next = NULL;
    new_node->prv = NULL;
    return new_node;
}

void fill_stack_a(t_list *stack, int *arr, int size)
{
    int i;
    t_node *new_node;
    new_node = NULL;

    if (!stack || !arr || size <= 0)
    {
        return;
    }

    i = 0;
    while (i < size)
    {
        new_node = create_node(arr[i]);
        if (!new_node)
        {
            return;
        }
        append_to_stack(stack, new_node);
        i++;
    }
}

void free_stack(t_list *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return;

    current = stack->head;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

void initialise_stack(t_list *stack)
{
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
}

void print_stack(t_list *stack, char letter)
{
    t_node *curent_node;

    if (!stack || stack->head == NULL)
    {
        ft_printf("Stack %c is emthy\n", letter);
        return;
    }
    ft_printf("====================================================================================================\n");

    ft_printf("***************************************\n");
    ft_printf("Stack %c\n", letter);
    ft_printf("***************************************\n");
    curent_node = stack->head;
    while (curent_node != NULL)
    {
        ft_printf("-------------------------------------------------------------------------------------------------\n");
        ft_printf("vlaue = %d, index = %d, target = %d, total_cost = %d,\nra_cost = %d, rb_cost = %d, rr_cost= %d,  rra_cost = %d, rrb_cost = %d, rrr_cost= %d\n", curent_node->value, curent_node->index, curent_node->target, curent_node->total_cost, curent_node->ra_cost, curent_node->rb_cost, curent_node->rr_cost, curent_node->rra_cost, curent_node->rrb_cost, curent_node->rrr_cost);
        ft_printf("-------------------------------------------------------------------------------------------------\n");
        curent_node = curent_node->next;
    }
    ft_printf("====================================================================================================\n");
}

void push_to_stack(t_list *source, t_list *destnation)
{
    t_node *current_node;

    if (!source || !destnation || !source->head)
    {
        return;
    }
    current_node = source->head;
    source->head = current_node->next;
    if (source->head != NULL)
    {
        source->head->prv = NULL;
    }
    else
    {
        source->tail = NULL;
    }
    current_node->prv = NULL;
    current_node->next = NULL;
    if (destnation->head == NULL)
    {
        destnation->head = current_node;
        destnation->tail = current_node;
    }
    else
    {
        current_node->next = destnation->head;
        destnation->head->prv = current_node;
        destnation->head = current_node;
    }
    source->size--;
    destnation->size++;
}

void pb(t_list *stack_a, t_list *stack_b)
{
    push_to_stack(stack_a, stack_b);
    ft_printf("pb\n");
    g_move_count++;
}

void pa(t_list *stack_a, t_list *stack_b)
{
    push_to_stack(stack_b, stack_a);
    ft_printf("pa\n");
    g_move_count++;
}

void fill_stack_b(t_list *stack_a, t_list *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    while (stack_a->size > 3)
    {
        pb(stack_a, stack_b);
    }
}

void roatate_stack(t_list *stack)
{
    t_node *current_node;
    if (!stack || stack->size < 2)
    {
        return;
    }
    current_node = stack->head;
    stack->head = current_node->next;
    stack->head->prv = NULL;
    current_node->prv = stack->tail;
    stack->tail->next = current_node;
    stack->tail = current_node;
    stack->tail->next = NULL;
}

void ra(t_list *stack_a)
{
    roatate_stack(stack_a);
    ft_printf("ra\n");
    g_move_count++;
}
void rb(t_list *stack_b)
{
    roatate_stack(stack_b);
    ft_printf("rb\n");
    g_move_count++;
}

void rr(t_list *stack_a, t_list *stack_b)
{

    roatate_stack(stack_a);
    roatate_stack(stack_b);
    ft_printf("rr\n");
    g_move_count++;
}

void reverce_roatate_stack(t_list *stack)
{
    t_node *current_node;

    if (!stack || stack->size < 2)
    {
        return;
    }
    current_node = stack->tail; // tail of stack the butem;
    stack->tail = current_node->prv;
    current_node->prv = NULL;
    current_node->next = stack->head;
    stack->head->prv = current_node;
    stack->head = current_node;
    stack->tail->next = NULL;
}

void rra(t_list *stack_a)
{
    if (!stack_a)
    {
        return;
    }
    reverce_roatate_stack(stack_a);
    ft_printf("rra\n");
    g_move_count++;
}
void rrb(t_list *stack_b)
{
    if (!stack_b)
    {
        return;
    }
    reverce_roatate_stack(stack_b);
    ft_printf("rrb\n");
    g_move_count++;
}

void rrr(t_list *stack_a, t_list *stack_b)
{
    if (!stack_a || !stack_b)
    {
        return;
    }
    reverce_roatate_stack(stack_a);
    reverce_roatate_stack(stack_b);
    ft_printf("rrr\n");
    g_move_count++;
}

void swap_list(t_list *stack)
{
    if (!stack || stack->size < 2)
    {
        return;
    }

    t_node *first_node;
    t_node *second_node;

    first_node = stack->head;
    second_node = stack->head->next;

    first_node->prv = second_node;
    first_node->next = second_node->next;

    second_node->prv = NULL;
    second_node->next = first_node;

    stack->head = second_node;

    if (stack->size == 2)
    {
        stack->tail = first_node;
    }
    else
    {
        first_node->next->prv = first_node;
    }
}

void sa(t_list *stack_a)
{
    if (!stack_a)
    {
        return;
    }
    swap_list(stack_a);
    ft_printf("sa\n");
    g_move_count++;
}

void sb(t_list *stack_b)
{
    if (!stack_b)
    {
        return;
    }
    swap_list(stack_b);
    ft_printf("sb\n");
    g_move_count++;
}

void ss(t_list *stack_a, t_list *stack_b)
{
    if (!stack_a || !stack_b)
    {
        return;
    }
    swap_list(stack_a);
    swap_list(stack_b);
    ft_printf("ss\n");
    g_move_count++;
}
void sort_three(t_list *stack)
{
    int a;
    int b;
    int c;

    if (!stack)
    {
        return;
    }
    a = stack->head->value;
    b = stack->head->next->value;
    c = stack->tail->value;
    if (a < b && b > c && c < a)
        rra(stack);
    else if (a > b && b < c && c > a)
    {
        sa(stack);
    }
    else if (a > b && b > c && c < a)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && c < a)
    {
        ra(stack);
    }
}

void assign_indexes(t_list *stack)
{
    int i;
    t_node *current_node;

    i = 0;
    if (!stack)
    {
        return;
    }

    current_node = stack->head;
    while (i < stack->size)
    {
        current_node->index = i;
        current_node = current_node->next;
        i++;
    }
}

t_node *find_min_node_value(t_list *stack)
{
    t_node *curent_node;
    t_node *min_value_node;

    if (!stack || stack->size == 0)
    {
        return NULL;
    }
    min_value_node = stack->head;
    curent_node = min_value_node->next;
    while (curent_node != NULL)
    {
        if (min_value_node->value > curent_node->value)
        {
            min_value_node = curent_node;
        }
        curent_node = curent_node->next;
    }
    return min_value_node;
}

int is_sorted(t_list *stack)
{
    t_node *current;

    if (!stack || stack->size == 0)
        return 1;

    current = stack->head;
    while (current->next != NULL)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

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

void write_stack_to_file(t_list *stack, const char *filename)
{
    FILE *file;
    t_node *current;
    int count;

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
    fprintf(file, "\n\n--- END ---\n");
    fclose(file);

    ft_printf("✓ Stack saved to file: %s\n", filename);
}

void assign_target(t_list *source, t_list *destnation)
{
    t_node *curent_source_node;
    t_node *target_node;
    t_node *curent_destnation_node;

    if (!source || !destnation || source->size == 0 || destnation->size == 0)
    {
        return;
    }

    curent_source_node = source->head; // 9
    target_node = NULL;                // NULL
    curent_destnation_node = NULL;     // NULL

    while (curent_source_node != NULL) // IN THE FIERST == 9
    {
        target_node = NULL;                        // NULL
        curent_destnation_node = destnation->head; // EQULES -5
        while (curent_destnation_node != NULL)     // it is not null
        {
            if (/*9*/ curent_source_node->value < /*-5*/ curent_destnation_node->value)
            {
                if (target_node == NULL || curent_destnation_node->value < target_node->value)
                {
                    target_node = curent_destnation_node;
                }
            }
            curent_destnation_node = curent_destnation_node->next;
        }
        if (target_node == NULL)
        {
            target_node = find_min_node_value(destnation);
        }
        curent_source_node->target = target_node->index;
        curent_source_node = curent_source_node->next;
    }
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

void calculate_cost(t_list *source, t_list *destanation)
{
    t_node *curent_node;
    if (!source || !destanation || source->size == 0 || destanation->size == 0)
    {
        return;
    }

    curent_node = source->head;
    int src_fwd;
    int src_back;
    int dest_fwd;
    int dest_back;

    int cost_rr;
    int cost_rrr;
    int cost_rb_rra;
    int cost_rrb_ra;
    int min_cost;

    while (curent_node != NULL)
    {
        src_fwd = curent_node->index;
        dest_fwd = curent_node->target;
        src_back = source->size - src_fwd;
        dest_back = destanation->size - dest_fwd;

        // Strategy 1: Both rotate forward (rr + remaining ra/rb)
        cost_rr = src_fwd + dest_fwd - min(src_fwd, dest_fwd);

        // Strategy 2: Both rotate backward (rrr + remaining rra/rrb)
        cost_rrr = src_back + dest_back - min(src_back, dest_back);

        // Strategy 3: Source forward, destination backward (rb + rra)
        cost_rb_rra = src_fwd + dest_back;

        // Strategy 4: Source backward, destination forward (rrb + ra)
        cost_rrb_ra = src_back + dest_fwd;

        // Find the minimum cost strategy
        min_cost = cost_rr;
        curent_node->rr_cost = min(src_fwd, dest_fwd);
        curent_node->rb_cost = src_fwd - curent_node->rr_cost;
        curent_node->ra_cost = dest_fwd - curent_node->rr_cost;
        curent_node->rrr_cost = 0;
        curent_node->rrb_cost = 0;
        curent_node->rra_cost = 0;

        if (cost_rrr < min_cost)
        {
            min_cost = cost_rrr;
            curent_node->rrr_cost = min(src_back, dest_back);
            curent_node->rrb_cost = src_back - curent_node->rrr_cost;
            curent_node->rra_cost = dest_back - curent_node->rrr_cost;
            curent_node->rr_cost = 0;
            curent_node->rb_cost = 0;
            curent_node->ra_cost = 0;
        }

        if (cost_rb_rra < min_cost)
        {
            min_cost = cost_rb_rra;
            curent_node->rb_cost = src_fwd;
            curent_node->rra_cost = dest_back;
            curent_node->rr_cost = 0;
            curent_node->ra_cost = 0;
            curent_node->rrr_cost = 0;
            curent_node->rrb_cost = 0;
        }

        if (cost_rrb_ra < min_cost)
        {
            min_cost = cost_rrb_ra;
            curent_node->rrb_cost = src_back;
            curent_node->ra_cost = dest_fwd;
            curent_node->rr_cost = 0;
            curent_node->rb_cost = 0;
            curent_node->rrr_cost = 0;
            curent_node->rra_cost = 0;
        }

        curent_node->total_cost = min_cost;
        curent_node = curent_node->next;
    }
}
void execute_moves(t_list *stack_a, t_list *stack_b, t_node *curent_node)
{
    int i;
    if (!stack_a || !stack_b || stack_b->size == 0)
    {
        return;
    }

    i = 0;
    while (i < curent_node->ra_cost)
    {
        ra(stack_a);
        i++;
    }
    i = 0;
    while (i < curent_node->rb_cost)
    {
        rb(stack_b);
        i++;
    }

    i = 0;
    while (i < curent_node->rra_cost)
    {
        rra(stack_a);
        i++;
    }
    i = 0;
    while (i < curent_node->rrb_cost)
    {
        rrb(stack_b);
        i++;
    }
    i = 0;
    while (i < curent_node->rr_cost)
    {
        rr(stack_a, stack_b);
        i++;
    }

    i = 0;
    while (i < curent_node->rrr_cost)
    {
        rrr(stack_a, stack_b);
        i++;
    }

    pa(stack_a, stack_b);
}

t_node *find_min_node_cost(t_list *stack)
{
    t_node *curent_node;
    t_node *min_cost_node;
    if (!stack || stack->size == 0)
    {
        return NULL;
    }
    min_cost_node = stack->head;
    curent_node = min_cost_node->next;
    while (curent_node != NULL)
    {
        if (curent_node->total_cost < min_cost_node->total_cost)
        {
            min_cost_node = curent_node;
        }
        curent_node = curent_node->next;
    }
    return min_cost_node;
}
void init_stack_cost(t_list *stack)
{
    t_node *curent_node;
    if (!stack || stack->size == 0)
    {
        return;
    }

    curent_node = stack->head;
    while (curent_node != NULL)
    {
        curent_node->ra_cost = 0;
        curent_node->rb_cost = 0;
        curent_node->rr_cost = 0;
        curent_node->rra_cost = 0;
        curent_node->rrb_cost = 0;
        curent_node->rrr_cost = 0;
        curent_node->total_cost = 0;
        curent_node = curent_node->next;
    }
}
int main()
{
    int data[] = {-28903, -2537, -2366, -661, 77, -33, 750, 43732, -833, -416,
                  979, -8001, 180, 7548, 31875, 329, -1468, -5297, 6781, 970,
                  7361, 28920, -142, -1701, 35455, -233, 22152, -317, 35800, -1393,
                  31341, -39426, -22425, -30904, -6635, 41651, 7119, -13875, -38281, -9002,
                  -8530, -491, -124, -37680, 451, -942, 6219, 294, 27038, 30064,
                  -326, -9236, -616, -5604, 3124, -887, -16909, -5039, 19276, -13164,
                  -905, 6506, 45695, -5870, 143, -813, -6994, -33860, -440, 9259,
                  4672, -5372, -1554, 2671, 3903, -141, 892, 515, 2702, 5367,
                  1845, -8535, 31117, -9718, -382, 2052, 2200, -180, -518, -993,
                  -1296, 530, 583, -1849, -4951, -378, -1635, 30411, -16199, -9325,
                  -44576, -20434, 7037, -2317, 1661, -63, 688, -365, -23510, 49921,
                  2479, 71, 956, 31060, -4590, -6813, 111, -23894, -9231, 370,
                  -721, 831, -292, 46875, 34746, -592, 10052, 5807, -567, -5280,
                  25940, 49577, 26320, -799, -1527, 359, -835, 35728, -955, 292,
                  49112, -49657, -16397, -21518, -31374, 9065, 30661, 11962, -961, 11141,
                  7658, 806, 15266, 32192, -21246, -733, -41806, -3369, 6909, 219,
                  -837, -441, -3212, -40562, 4823, 8902, 3066, -535, -479, 336,
                  9000, 819, 18746, -2933, 4849, -182, -2862, 805, 691, -39,
                  6707, -7505, 2817, 8741, 31289, -577, -8973, -34694, -26521, -337,
                  -8125, 346, -113, 2262, -26177, -7259, -41357, 27477, -46544, -658,
                  -12124, 6492, 33269, -33933, -17262, -7950, 9194, -7228, 82, -10908,
                  13914, -105, -41, -21376, 21969, 6006, 488, -45373, -540, 10390,
                  9444, -39202, 519, -1244, 6928, -172, 125, 39130, -27835, -3671,
                  -7480, 8111, 46027, 368, 6636, -3461, -268, -6046, 2023, 8813,
                  2519, -9416, -40582, 8143, -32475, 4009, 9533, 358, -9972, -42067,
                  707, -82, -6410, 9612, 35376, -3652, -11687, 35187, -47961, 46852,
                  -39262, 6319, -154, 720, -2702, -32752, 693, 2016, -20608, -349,
                  -436, 523, 978, -4512, -22508, -574, -888, -23739, 773, 47680,
                  1773, -25818, -749, 902, 7887, -88, -31146, 939, 6626, -26887,
                  -821, 25134, 8634, 15777, 45874, -20711, -671, -38108, -318, 1423,
                  -346, 6444, -899, 46288, -2647, 19002, -9473, 1482, -36503, -1258,
                  -23825, -7212, -1017, 349, -632, 969, 9767, 7822, 715, -9655,
                  2435, 86, 28304, -11983, 3891, -875, -5229, -645, -2523, 702,
                  -24671, 6589, 235, -212, -8715, -3004, 862, 296, -4723, -6081,
                  -185, 481, 9529, 408, -28710, -9652, 45714, -836, 568, -2203,
                  -3832, -400, 1337, 4095, -15001, 5290, 17926, -46255, -611, 9716,
                  1541, -6068, -41092, -3654, -10919, 670, -333, 352, -989, 18264,
                  -41087, -7039, 9823, -44587, 3552, -810, -594, -40564, -979, -3170,
                  1697, -8649, 2714, 538, -49375, 31109, 31943, 14103, 7419, -497,
                  -369, 913, 8878, 7149, -8348, -4011, -44217, -71, 22440, 1233,
                  -53, -10638, 933, 436, -1364, -8796, 16039, -8338, 8048, -1723,
                  -630, 24525, -6774, -14375, 34613, -904, -47953, 304, 14773, -3183,
                  961, -28713, 34737, 513, 41707, -1919, 558, 319, 126, 2750,
                  3945, -345, -14952, -710, 37577, -385, 37279, 18876, 92, 934,
                  -6180, 461, -392, 685, 1844, -428, 156, 3303, -45, 455,
                  -1394, 8657, -4428, -725, 45594, -8904, 33361, 9133, 421, -20066,
                  -44182, 678, 1700, -3713, 8557, -806, 3551, -38185, 6579, 374,
                  -669, -556, 966, 27398, -46898, -856, -1235, 1237, -40683, -43484,
                  3754, 24573, -546, -8326, 8739, -5016, -132, 440, 642, -4475,
                  -11745, -736, 620, 5418, -2642, -29788, -972, -355, 7025, 9689};
    int data_size = sizeof(data) / sizeof(int);
    t_list stack_a;
    t_list stack_b;
    t_node *min_cost_node;
    int ra_cost;
    int rra_cost;
    initialise_stack(&stack_a);
    initialise_stack(&stack_b);
    fill_stack_a(&stack_a, data, data_size);

    fill_stack_b(&stack_a, &stack_b);

    sort_three(&stack_a);

    while (stack_b.size > 0)
    {
        init_stack_cost(&stack_b);
        assign_indexes(&stack_a);
        assign_indexes(&stack_b);
        assign_target(&stack_b, &stack_a);
        calculate_cost(&stack_b, &stack_a);
        min_cost_node = find_min_node_cost(&stack_b);

        execute_moves(&stack_a, &stack_b, min_cost_node);
    }

    assign_indexes(&stack_a);

    // Only rotate if not already sorted
    if (!is_sorted(&stack_a))
    {
        min_cost_node = find_min_node_value(&stack_a);
        ra_cost = min_cost_node->index;
        rra_cost = stack_a.size - ra_cost;

        int i;
        i = 0;
        if (ra_cost < rra_cost)
        {
            while (i < ra_cost)
            {
                ra(&stack_a);
                i++;
            }
        }
        else
        {
            while (i < rra_cost)
            {
                rra(&stack_a);
                i++;
            }
        }
    }

    if (is_sorted(&stack_a))
    {
        ft_printf("\n✓ Stack is correctly sorted!\n");
        print_sorted_values(&stack_a);
        write_stack_to_file(&stack_a, "sorted_stack.txt");
    }
    else
    {
        print_sorted_values(&stack_a);
        write_stack_to_file(&stack_a, "sorted_stack.txt");
        ft_printf("\n✗ ERROR: Stack is NOT sorted!\n");
    }

    ft_printf("\n========================================\n");
    ft_printf("Total moves: %d\n", g_move_count);
    ft_printf("========================================\n");

    free_stack(&stack_a);
    free_stack(&stack_b);

    return 0;
}