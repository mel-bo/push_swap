/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:15:56 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/24 22:51:36 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_n(stack *s)
{
	node	*tmp;

	if (s->size == 2)
	{
		tmp = s->head;
		s->head->preview = s->tail;
		s->tail->next = s->head;
		s->head->next = NULL;
		s->tail->preview = NULL;
		s->head = s->tail;
		s->tail = tmp;
	}
	else
	{
		tmp = s->head->next;
		s->head->next = tmp->next;
		s->head->preview = tmp;
		tmp->next = s->head;
		tmp->preview = NULL;
		s->head = tmp;
	}
}

void	rotate_n(stack *s)
{
	node	*tmp;
	
	tmp = s->head->next;
	if (s->size == 2)
		swap_n(s);
	else
	{
		s->tail->next = s->head;
		s->head->preview = s->tail;
		s->head->next = NULL;
		tmp->preview = NULL;
		s->tail = s->head;
		s->head = tmp;
	}
}

void	rev_rotate(stack *s)
{
	node	*tmp;

	tmp = s->tail->preview;
	if (s->size == 2)
		swap_n(s);
	else
	{
		s->head->preview = s->tail;
		s->tail->next = s->head;
		s->tail->preview = NULL;
		tmp->next = NULL;
		s->head = s->tail;
		s->tail = tmp;
	}
}

void	push_n(stack *x, stack *y)
{
	node	*tmp;
	
	if (!y)
	{
		y->head = x->head;
		y->tail = x->head;
		x->head = x->head->next;
		x->head->preview = NULL;
		y->head->preview = NULL;
		y->head->next = NULL;
	}
	else
	{
		tmp = y->head;
		y->head = x->head;
		x->head = x->head->next;
		if (x->head != NULL)
			x->head->preview = NULL;
		y->head->next = tmp;
		tmp->preview = y->head;
	}
	if (x->head == NULL)
		x->tail = NULL;
}
