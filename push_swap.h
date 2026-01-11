#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


typedef struct node
{
    int value;
    int index;
    int target;
    int total_cost;
    int ra_cost;
    int rb_cost;
    int rr_cost;
    int rra_cost;
    int rrb_cost;
    int rrr_cost;
    struct node *next;
    struct node *prv;
}       t_node;

typedef struct list
{
    t_node  *head;
    t_node  *tail;
    int     size;
}             t_list;

#endif