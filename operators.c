/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:15:56 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/07 16:40:59 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(stack *s)
{
	node	*tmp;

tmp = s->head;
	if (s->size == 2)
	{
		tmp->x = s->head->x;
		s->head->x = s->tail->x;
		s->tail->x = tmp->x;
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
