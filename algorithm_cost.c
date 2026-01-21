#include "push_swap.h"
#include <stdlib.h>

typedef struct s_dist
{
	int		sf;
	int		sb;
	int		df;
	int		db;
}			t_dist;

static void	set_strategy_0(t_node *n, t_dist d)
{
	n->rr_cost = min(d.sf, d.df);
	n->rb_cost = d.sf - n->rr_cost;
	n->ra_cost = d.df - n->rr_cost;
	n->rrr_cost = 0;
	n->rrb_cost = 0;
	n->rra_cost = 0;
}

static void	set_strategy_1(t_node *n, t_dist d)
{
	n->rrr_cost = min(d.sb, d.db);
	n->rrb_cost = d.sb - n->rrr_cost;
	n->rra_cost = d.db - n->rrr_cost;
	n->rr_cost = 0;
	n->rb_cost = 0;
	n->ra_cost = 0;
}

static void	set_strategy_2_3(t_node *n, t_dist d, int strategy)
{
	n->rr_cost = 0;
	n->rrr_cost = 0;
	if (strategy == 2)
	{
		n->rb_cost = d.sf;
		n->rra_cost = d.db;
		n->ra_cost = 0;
		n->rrb_cost = 0;
	}
	else
	{
		n->rrb_cost = d.sb;
		n->ra_cost = d.df;
		n->rb_cost = 0;
		n->rra_cost = 0;
	}
}

static int	find_min_strategy(t_node *n, int c[4], t_dist d)
{
	int	best;

	best = 0;
	if (c[1] < c[best])
		best = 1;
	if (c[2] < c[best])
		best = 2;
	if (c[3] < c[best])
		best = 3;
	if (best == 0)
		set_strategy_0(n, d);
	else if (best == 1)
		set_strategy_1(n, d);
	else
		set_strategy_2_3(n, d, best);
	return (c[best]);
}

int	calc_node_cost(t_node *node, t_list *src, t_list *dest)
{
	int costs[4];
	t_dist d;

	d.sf = node->index;
	d.df = node->target;
	d.sb = src->size - d.sf;
	d.db = dest->size - d.df;
	costs[0] = d.sf + d.df - min(d.sf, d.df);
	costs[1] = d.sb + d.db - min(d.sb, d.db);
	costs[2] = d.sf + d.db;
	costs[3] = d.sb + d.df;
	return (find_min_strategy(node, costs, d));
}