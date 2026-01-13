#include <stdlib.h>
#include "push_swap.h"

static void set_costs_strategy_rr(t_node *node, int src_fwd, int dest_fwd)
{
    node->rr_cost = min(src_fwd, dest_fwd);
    node->rb_cost = src_fwd - node->rr_cost;
    node->ra_cost = dest_fwd - node->rr_cost;
    node->rrr_cost = 0;
    node->rrb_cost = 0;
    node->rra_cost = 0;
}

static void set_costs_strategy_rrr(t_node *node, int src_back, int dest_back)
{
    node->rrr_cost = min(src_back, dest_back);
    node->rrb_cost = src_back - node->rrr_cost;
    node->rra_cost = dest_back - node->rrr_cost;
    node->rr_cost = 0;
    node->rb_cost = 0;
    node->ra_cost = 0;
}

static void set_costs_strategy_rb_rra(t_node *node, int src_fwd, int dest_back)
{
    node->rb_cost = src_fwd;
    node->rra_cost = dest_back;
    node->rr_cost = 0;
    node->ra_cost = 0;
    node->rrr_cost = 0;
    node->rrb_cost = 0;
}

static void set_costs_strategy_rrb_ra(t_node *node, int src_back, int dest_fwd)
{
    node->rrb_cost = src_back;
    node->ra_cost = dest_fwd;
    node->rr_cost = 0;
    node->rb_cost = 0;
    node->rrr_cost = 0;
    node->rra_cost = 0;
}

int calc_node_cost(t_node *node, t_list *src, t_list *dest)
{
    int src_fwd;
    int src_back;
    int dest_fwd;
    int dest_back;
    int costs[4];
    int min_cost;

    src_fwd = node->index;
    dest_fwd = node->target;
    src_back = src->size - src_fwd;
    dest_back = dest->size - dest_fwd;
    costs[0] = src_fwd + dest_fwd - min(src_fwd, dest_fwd);
    costs[1] = src_back + dest_back - min(src_back, dest_back);
    costs[2] = src_fwd + dest_back;
    costs[3] = src_back + dest_fwd;
    min_cost = costs[0];
    set_costs_strategy_rr(node, src_fwd, dest_fwd);
    if (costs[1] < min_cost)
    {
        min_cost = costs[1];
        set_costs_strategy_rrr(node, src_back, dest_back);
    }
    if (costs[2] < min_cost)
    {
        min_cost = costs[2];
        set_costs_strategy_rb_rra(node, src_fwd, dest_back);
    }
    if (costs[3] < min_cost)
    {
        min_cost = costs[3];
        set_costs_strategy_rrb_ra(node, src_back, dest_fwd);
    }
    return (min_cost);
}