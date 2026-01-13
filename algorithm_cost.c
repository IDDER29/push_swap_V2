#include "push_swap.h"
#include <stdlib.h>

static void	set_strategy(t_node *n, int strategy, int sf, int sb, int df,
		int db)
{
	if (strategy == 0)
	{
		n->rr_cost = min(sf, df);
		n->rb_cost = sf - n->rr_cost;
		n->ra_cost = df - n->rr_cost;
		n->rrr_cost = 0;
		n->rrb_cost = 0;
		n->rra_cost = 0;
	}
	else if (strategy == 1)
	{
		n->rrr_cost = min(sb, db);
		n->rrb_cost = sb - n->rrr_cost;
		n->rra_cost = db - n->rrr_cost;
		n->rr_cost = 0;
		n->rb_cost = 0;
		n->ra_cost = 0;
	}
	else if (strategy == 2)
	{
		n->rb_cost = sf;
		n->rra_cost = db;
		n->rr_cost = 0;
		n->ra_cost = 0;
		n->rrr_cost = 0;
		n->rrb_cost = 0;
	}
	else
	{
		n->rrb_cost = sb;
		n->ra_cost = df;
		n->rr_cost = 0;
		n->rb_cost = 0;
		n->rrr_cost = 0;
		n->rra_cost = 0;
	}
}

static int	find_min_strategy(t_node *n, int c[4], int sf, int sb, int df,
		int db)
{
	int	min_cost;
	int	best_strategy;

	min_cost = c[0];
	best_strategy = 0;
	if (c[1] < min_cost && (min_cost = c[1]))
		best_strategy = 1;
	if (c[2] < min_cost && (min_cost = c[2]))
		best_strategy = 2;
	if (c[3] < min_cost && (min_cost = c[3]))
		best_strategy = 3;
	set_strategy(n, best_strategy, sf, sb, df, db);
	return (min_cost);
}

int	calc_node_cost(t_node *node, t_list *src, t_list *dest)
{
	int costs[4];
	int sf;
	int sb;
	int df;
	int db;

	sf = node->index;
	df = node->target;
	sb = src->size - sf;
	db = dest->size - df;
	costs[0] = sf + df - min(sf, df);
	costs[1] = sb + db - min(sb, db);
	costs[2] = sf + db;
	costs[3] = sb + df;
	return (find_min_strategy(node, costs, sf, sb, df, db));
}