/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:35:29 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/03 22:20:46 by mel-bout         ###   ########.fr       */
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
	int	target;
	int pos;
}	node;

typedef struct 
{
	node	*head;
	node	*tail;
	int		size;
	int 	median;
	int		cost;
	int		new_cost;
	int		node_exe;
	int		sa;
	int		sb;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		ss;
	int		rr;
	int		rrr;
}	stack;

int		ft_isdigit(char **s);
int		parser(char **tab, stack *a);
void	enqueue(stack *q, int n);
void	swap_n(stack *s);
void	rotate_n(stack *s);
void	rev_rotate(stack *s);
void	push_n(stack *x, stack *y);
void	turk_algo(stack *a, stack *b);
void    target_small(stack *x, stack *y);
void    get_order(stack *x, stack *y);
void	cost_analysis(stack *x, stack *y);

#endif