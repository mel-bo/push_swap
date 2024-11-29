/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:23:36 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/29 20:59:41 by mel-bout         ###   ########.fr       */
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
		ptr_a = ptr_a->next;
	}
}
