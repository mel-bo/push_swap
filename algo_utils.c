/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:23:36 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/03 23:07:38 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_order(stack *x, stack *y)
{
	node	*ptr;
	int		i;

	i = 1;
	ptr = x->head;
	while (x && ptr != NULL)
	{
		ptr->pos = i;
		ptr = ptr->next;
		i++;
	}
	i = 1;
	ptr = y->head;
	while (y && ptr != NULL)
	{
		ptr->pos = i;
		ptr = ptr->next;
		i++;
	}
	x->median = x->size / 2;
	y->median = y->size / 2;
}

int	first_ref(int x, stack *y, int *target)
{
	node	*ptr;
	int		ref;
	
	ptr = y->head;
	while (ptr != NULL)
	{
		if (x > ptr->x)
		{
			(*target) = ptr->pos;
			ref = x - ptr->x;
			return (ref);
		}
		ptr = ptr->next;
	}
	return (0);
}

void	target_max(int x, stack *y, int *target)
{
	node	*ptr;
	int		curr;
	
	ptr = y->head;
	curr = x;
	while (ptr != NULL)
	{
		if (ptr->x > curr)
		{
			curr = ptr->x;
			(*target) = ptr->pos;
		}
		ptr = ptr->next;
	}	
}

void	target_small(stack *x, stack *y)
{
	node	*ptr_a;
	node	*ptr_b;
	int		old_ref;
	int		new_ref;

	ptr_a = x->head;
	while (ptr_a != NULL)
	{
		old_ref = first_ref(ptr_a->x, y, &ptr_a->target);
		if (old_ref == 0)
			target_max(ptr_a->x, y, &ptr_a->target);
		ptr_b = y->head;
		while (old_ref != 0 && ptr_b != NULL)
		{
			new_ref = ptr_a->x - ptr_b->x;
			if (new_ref > 0 && old_ref > new_ref)
			{
				ptr_a->target = ptr_b->pos;
				old_ref = new_ref;
			}
			ptr_b = ptr_b->next;
		}
		printf("%d => %d\n", ptr_a->x, ptr_a->target);
		ptr_a = ptr_a->next;
	}
}

void	cost_rr(stack *x)
{
	int	res;
	
	res = x->ra - x->rb;
	if (res > 0)
	{
		x->rr = x->rb;
		x->rb = 0;
		x->ra = res;
		x->cost = x->rr + x->ra;
	}
	else if (res < 0)
	{
		x->rr = x->ra;
		x->ra = 0;
		x->rb = res;
		x->cost = x->rr + x->rb;
	}
	else
	{
		x->rr = x->ra;
		x->ra = 0;
		x->rb = 0;
		x->cost = x->rr;
	}
}

void	cost_rrr(stack *x)
{
	int	res;

	res = x->rra - x->rrb;
	if (res > 0)
	{
		x->rrr = x->rrb;
		x->rrb = 0;
		x->rra = res;
		x->cost = x->rrr + x->rra;
	}
	else if (res < 0)
	{
		x->rrr = x->rra;
		x->rra = 0;
		x->rrb = res;
		x->cost = x->rrr + x->rrb;
	}
	else
	{
		x->rrr = x->rra;
		x->rra = 0;
		x->rrb = 0;
		x->cost = x->rrr;
	}
}

void	cost_calc(stack *x)
{
	if (x->sa > 0 && x->sb > 0)
	{
		x->ss = 1;
		x->sa = 0;
		x->sb = 0;
		x->cost = 1;
	}
	else if (x->ra > 0 && x->rb > 0)
		cost_rr(x);
	else if (x->rra > 0 && x->rrb > 0)
		cost_rrr(x);
	else
	{
		x->cost = x->sa + x->sb + x->ra + x->rb + x->rra + x->rrb;
	}
}

void	cost_pos_1(stack *x, stack *y, node *ptr)
{
	if (ptr->target == 1)
		x->cost = 0;
	else if (ptr->target == 2)
	{
		x->sb = 1;
		x->cost = 1;
		if (x->new_cost == -1)
			x->new_cost = x->cost;
	}
	else if (ptr->target > 2)
	{
		if (y->median >= ptr->target)
		{
			x->rb = ptr->target - 1;
			x->cost = ptr->target - 1;
		}
		else if (ptr->target > y->median)
		{
			x->rrb = y->size - ptr->target + 1;
			x->cost = y->size - ptr->target + 1;
		}
		if (x->new_cost == -1)
			x->new_cost = x->cost;
	}
}

void	cost_pos_2(stack *x, stack *y, node *ptr)
{
	if (ptr->target == 2)
	{
		x->sa = 1;
		x->sb = 1;
		cost_calc(x);
	}
	else if (ptr->target > 2)
	{
		if (y->median >= ptr->target)
		{
			x->sa = 1;
			x->rb = ptr->target - 1;
			cost_calc(x);
		}
		else if (ptr->target > y->median)
		{
			x->sa = 1;
			x->rrb = y->size - ptr->target + 1;
			cost_calc(x);
		}
	}
}

void	cost(stack *x, stack *y, node *ptr)
{
	if (x->median >= ptr->pos)
	{
		x->ra = ptr->pos - 1;
		if (y->median >= ptr->target)
			x->rb = ptr->target - 1;
		else if (ptr->target > y->median)
			x->rrb = y->size - ptr->target + 1;
		cost_calc(x);
	}
	else if (ptr->pos > x->median)
	{
		x->rra = x->size - ptr->pos + 1;
		if (y->median >= ptr->target)
			x->rb = ptr->target - 1;
		else if (ptr->target > y->median)
			x->rrb = y->size - ptr->target + 1;
		cost_calc(x);
	}
}

void	cost_analysis(stack *x, stack *y)
{
	node	*ptr;

	ptr = x->head;
	if (ptr->pos == 1)
		cost_pos_1(x, y, ptr);
	else if (ptr->pos == 2)
	{
		if (ptr->target == 1)
		{
			x->cost = 1;
			x->sa = 1;
		}
		else
			cost_pos_2(x, y, ptr);
	}
	else if (ptr->pos > 2)
		cost(x, y, ptr);
	if (x->cost == 0)
		return ;
	else if (x->new_cost > x->cost)
		x->new_cost = x->cost; 
}
void	cost_exe(stack *a, stack *b)
{
	if (a->cost == 0)
		push_n(a, b);
	else
	{
		
	}
}