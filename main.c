#include <stdlib.h>
#include "push_swap.h"
#include "ft_printf.h"

void append_to_stack(t_list *stack, t_node *new_node)
{
    if(!stack || !new_node)
    {
        return;
    }

    if(stack->head == NULL)
    {
        stack->head = new_node;
        stack->tail = new_node;
    }else
    {
        stack->tail->next = new_node;
        new_node->prv= stack->tail;
        stack->tail = new_node;
    }
    stack->size++;
}

t_node *create_node(int num)
{
    t_node *new_node;
    new_node = malloc(sizeof(t_node));
    if(!new_node)
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

    if(!stack || !arr || size <= 0)
    {
        return;
    }

    i = 0;
    while(i < size)
    {
        new_node = create_node(arr[i]);
        if(!new_node)
        {
            return;
        }
        append_to_stack(stack, new_node);
        i++;
    }

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

    if(!stack || stack->head == NULL)
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
        ft_printf("vlaue = %d, index = %d, target = %d, total_cost = %d,\nra_cost = %d, rb_cost = %d, rr_cost= %d,  rra_cost = %d, rrb_cost = %d, rrr_cost= %d\n", curent_node->value, curent_node->index, curent_node->target, curent_node->total_cost ,curent_node->ra_cost, curent_node->rb_cost, curent_node->rr_cost, curent_node->rra_cost, curent_node->rrb_cost, curent_node->rrr_cost);
        ft_printf("-------------------------------------------------------------------------------------------------\n");
        curent_node = curent_node->next;

    }
    ft_printf("====================================================================================================\n");
}

void push_to_stack(t_list *source, t_list *destnation)
{
    t_node *current_node;

    if(!source || !destnation)
    {
        return;
    }
    current_node = source->head;
    source->head = current_node->next;
    current_node->prv = NULL; 
    current_node->next = NULL;
    if(destnation->head == NULL)
    {
        destnation->head = current_node;
        destnation->tail = current_node;
    }else
    {
        current_node->next = destnation->head;
        destnation->head = current_node;
    }
    source->size--;
    destnation->size++;
}

void pb(t_list *stack_a, t_list *stack_b)
{
    push_to_stack(stack_a, stack_b);
    ft_printf("pb\n");
}

void pa(t_list *stack_a, t_list *stack_b)
{
    push_to_stack(stack_b, stack_a);
    ft_printf("pa\n");
}

void fill_stack_b(t_list *stack_a, t_list *stack_b)
{
    if(!stack_a || !stack_b)
        return;
    while (stack_a->size > 3)
    {
        pb(stack_a, stack_b);
    }
}

void roatate_stack(t_list *stack)
{
    t_node *current_node;
    if(!stack || stack->size < 2)
    {
        return;
    }
    current_node = stack->head;
    stack->head = current_node->next;
    stack->head->prv =  NULL;
    current_node->prv = stack->tail;
    stack->tail->next = current_node;
    stack->tail = current_node;
    stack->tail->next = NULL;
    
}

void ra(t_list *stack_a)
{
    roatate_stack(stack_a);
    ft_printf("ra\n");
}
void rb(t_list *stack_b)
{
    roatate_stack(stack_b);
    ft_printf("rb\n");
}

void rr(t_list *stack_a, t_list *stack_b)
{

    
    roatate_stack(stack_a);
    roatate_stack(stack_b);
    ft_printf("rr\n");
}

void reverce_roatate_stack(t_list *stack)
{
    t_node *current_node;

    if(!stack || stack->size < 2)
    {
        return;
    }
    current_node = stack->tail;//tail of stack the butem;
    stack->tail = current_node->prv;
    current_node->prv = NULL;
    current_node->next = stack->head;
    stack->head->prv = current_node;
    stack->head = current_node;
    stack->tail->next = NULL;

   

}

void rra(t_list *stack_a)
{
    if(!stack_a)
    {
        return;
    }
    reverce_roatate_stack(stack_a);
    ft_printf("rra\n");
}
void rrb(t_list *stack_b)
{
    if(!stack_b)
    {
        return;
    }
    reverce_roatate_stack(stack_b);
    ft_printf("rrb\n");
}

void rrr(t_list *stack_a, t_list *stack_b)
{
    if(!stack_a || !stack_b)
    {
        return;
    }
    reverce_roatate_stack(stack_a);
    reverce_roatate_stack(stack_b);
    ft_printf("rrr\n");
}

void swap_list(t_list *stack)
{
    if(!stack || stack->size < 2)
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

    if(stack->size == 2)
    {
        stack->tail = first_node;
    }else
    {
        stack->tail->prv = first_node;
    }

}

void sa(t_list *stack_a)
{
    if(!stack_a)
    {
        return;
    }
    swap_list(stack_a);
    ft_printf("sa\n");
}

void sb(t_list *stack_b)
{
    if(!stack_b)
    {
        return;
    }
    swap_list(stack_b);
    ft_printf("sb\n");
}

void ss(t_list *stack_a, t_list *stack_b)
{
    if(!stack_a || !stack_b)
    {
        return;
    }
    swap_list(stack_a);
    swap_list(stack_b);
    ft_printf("ss\n");
}
void sort_three(t_list *stack)
{
    int a;
    int b;
    int c;

    if(!stack)
    {
        return;
    }
    a = stack->head->value;
    b = stack->head->next->value;
    c = stack->tail->value;
    if(a < b && b>c && c < a )
        rra(stack);
    if(a > b && b < c && c > a)
    {
        sa(stack);
    }else if(a > b && b > c && c < a )
    {
        sa(stack);
        rra(stack);
        
    }else if (a > b && b < c && c < a )
    {
        ra(stack);
    }
}

void assign_indexes(t_list *stack)
{
    int i;
    t_node *current_node;

    i = 0;
    if(!stack)
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

    if(!stack || stack->size == 0)
    {
        return NULL;
    }
    min_value_node = stack->head;
    curent_node = min_value_node->next;
    while (curent_node != NULL)
    {
        if(min_value_node->value > curent_node->value)
        {
            min_value_node = curent_node;
        }
        curent_node = curent_node->next;
    }
    return min_value_node;
}
void assign_target(t_list *source, t_list *destnation)
{
    t_node *curent_source_node;
    t_node *target_node;
    t_node *curent_destnation_node;

    if(!source || !destnation || source->size == 0 || destnation->size == 0)
    {
        return;
    }

    curent_source_node = source->head;// 9
    target_node = NULL;//NULL
    curent_destnation_node = NULL;//NULL

    while (curent_source_node != NULL)//IN THE FIERST == 9
    {
        target_node = NULL; // NULL
        curent_destnation_node = destnation->head; // EQULES -5
        while (curent_destnation_node != NULL) // it is not null
        { 
            if (/*9*/curent_source_node->value < /*-5*/curent_destnation_node->value  )
            {
                if(target_node == NULL || curent_destnation_node->value < target_node->value)
                {
                    target_node = curent_destnation_node;
                }
            }
            curent_destnation_node = curent_destnation_node->next;
        }
        if(target_node == NULL)
        {
            target_node = find_min_node_value(destnation);
        }
        curent_source_node->target = target_node->index;
        curent_source_node = curent_source_node->next;
    }
}

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

void calculate_cost(t_list *source, t_list *destanation)
{
    t_node *curent_node;
    if(!source || !destanation || source->size == 0 || destanation->size == 0)
    {
        return;
    }

    curent_node = source->head;
    int src_fwd;
    int src_back;
    int dest_fwd;
    int dest_back;
    
    int source_mid;
    int dest_mid;
    int rr_cost;
    int rrr_cost;

    source_mid = source->size / 2;
    dest_mid = destanation->size / 2;
while (curent_node != NULL)
{

     src_fwd = 0;
     src_back = 0;
     dest_fwd = 0;
     dest_back = 0;
    
     rr_cost = 0;
     rrr_cost = 0;


        src_fwd = curent_node->index; // 2
        dest_fwd = curent_node->target; // 2
        src_back = source->size - src_fwd; // 1
        dest_back = destanation->size - dest_fwd; // 5
        rr_cost = min(src_fwd, dest_fwd); // 2
        rrr_cost = min(src_back, dest_back); // 1

    if((curent_node->index <= source_mid && curent_node->target <= dest_mid) || ((src_fwd + dest_back) /*7*/ <= /**/ (src_fwd + dest_fwd - rr_cost)))
    { 
        curent_node->rr_cost = rr_cost;// 0 
        curent_node->rb_cost = src_fwd - rr_cost; // 0
        curent_node->ra_cost = dest_fwd - rr_cost; // 1
        curent_node->total_cost =  src_fwd + dest_fwd - rr_cost;

    }
    else if(curent_node->index >= source_mid && curent_node->target >= dest_mid)
    {   
        curent_node->rrr_cost = rrr_cost;
        curent_node->rrb_cost = src_back - rrr_cost;
        curent_node->rra_cost = dest_back - rrr_cost;
        curent_node->total_cost =  src_back  + dest_back - rrr_cost;

    }
    else if((src_fwd + dest_back) /*7*/ <= /**/ (src_fwd + dest_fwd - rr_cost) && 
                ((src_fwd + dest_back)) <= (src_back  + dest_back - rrr_cost) )
    {
            curent_node->rb_cost = src_fwd;
            curent_node->rra_cost = dest_back;
            curent_node->total_cost = src_fwd + dest_back;
    }
    else if((src_back + dest_fwd) <= (src_fwd + dest_fwd - rr_cost) && ((src_back + dest_fwd)) <= (src_back  + dest_back - rrr_cost) )
    {
        curent_node->rrb_cost = src_back;
        curent_node->ra_cost = dest_fwd;
        curent_node->total_cost = src_back + dest_fwd;
    }

    curent_node = curent_node->next;
}

}
void execute_moves( t_list *stack_a, t_list *stack_b, t_node *curent_node)
{
    int i;
    if(!stack_a || !stack_a || stack_b->size == 0)
    {
        return;
    }

        i = 0;
        while(i < curent_node->ra_cost)
        {
            ra(stack_a);
            i++;
        }
        i = 0;   
        while(i < curent_node->rb_cost)
        {
             rb(stack_b);
             i++;
        }
           
        i = 0;
        while(i < curent_node->rra_cost)
        {
            rra(stack_a);
            i++;
        }
        i = 0;   
        while(i++ < curent_node->rrb_cost)
        {
            rrb(stack_b);
            i++;
        }
         i = 0;
        while(i < curent_node->rr_cost)
        {
            rr(stack_a, stack_b);
            i++;
        }
            
        i = 0;   
        while(i < curent_node->rrr_cost)
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
    if(!stack || stack->size == 0)
    {
        return NULL;
    }
    min_cost_node = stack->head;
    curent_node = min_cost_node->next;
    while (curent_node != NULL)
    {
        if(curent_node->total_cost < min_cost_node->total_cost)
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
    if(!stack || stack->size == 0)
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
    int data[] = {12, 67, 3, 0, -5, 99, 8, 23, -1, 42};
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
    print_stack(&stack_a, 'A');
   min_cost_node = find_min_node_cost(&stack_a);
   ra_cost = 0;
   rra_cost = 0;
    ra_cost = min_cost_node->index;
    rra_cost = stack_a.size - ra_cost;
   
    int i;
    i = 0;
   if(ra_cost < rra_cost)
   {
    while (i <= ra_cost)
    {
        ra(&stack_a);
        i++;
    }
    
   }else
   {
     while (i <= rra_cost)
    {
        rra(&stack_a);
        i++;
    }
   }
   
    print_stack(&stack_a, 'A');

    return 0;
}