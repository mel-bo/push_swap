/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:25:18 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/30 21:00:21 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(stack *s)
{
	if (s->head->x > s->tail->x)
	{
		swap_n(s);
		ft_printf("sa\n");
	}	
}

void	mini_sort(stack *s)
{
	if (s->head->x > s->tail->x && s->head->x > s->head->next->x)
	{
		rotate_n(s);
		ft_printf("ra\n");
	}
	else if (s->tail->x < s->head->x && s->tail->x < s->head->next->x)
	{
		rev_rotate(s);
		ft_printf("rra\n");
	}
	if (s->head->x > s->head->next->x)
	{
		swap_n(s);
		ft_printf("sa\n");
	}
}

void	turk_algo(stack *a, stack *b)
{
	printf("turk_algo\n");
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		mini_sort(a);
	else if (a->size > 3)
	{
		push_n(a, b);
		if (a->size > 3)
			push_n(a, b);
		while (a->size > 3)
		{
			get_order(a, b);
			target_small(a, b);
			cost_analysis(a, b);
		}
	}
}
