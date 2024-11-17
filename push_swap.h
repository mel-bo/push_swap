/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:35:29 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/07 14:48:43 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	node
{
	int			x;
	struct node *preview;
	struct node	*next;
}	node;

typedef struct 
{
	node	*head;
	node	*tail;
	int	size;
	int	value;
}	stack;

int		ft_isdigit(char **s);
int		parser(char **tab, stack *a);
void	enqueue(stack *q, int n);
void	swap_s(stack *s);

#endif