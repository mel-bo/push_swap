/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:10:42 by mel-bout          #+#    #+#             */
/*   Updated: 2024/12/03 22:20:46 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_split(char **tab)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (tab[i])
	{
		count += words_count(tab[i], ' ');
		i++;
	}
	printf("count = %d\n", count);
}
void	init_queue(stack *a)
{
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	a->median = 0;
	a->cost = -1;
	a->new_cost = -1;
	a->sa = 0;
	a->sb = 0;
	a->ra = 0;
	a->rb = 0;
	a->rra = 0;
	a->rrb = 0;
	a->ss = 0;
	a->rr = 0;
	a->rrr = 0;
}

int	main(int argc, char **argv)
{
	stack	a;
	stack	b;

	init_queue(&a);
	init_queue(&b);
	if (argc < 2 || argv[1][0] == '\0')
		return (ft_printf("Error\n"), 1);
	//call_split(argv);
	if (parser((argv + 1), &a))
		return (ft_printf("Error\n"), 1);
	printf("*****stack_a*****\n");
	node *ptr;
	ptr = malloc(sizeof(node));
	if (!ptr)
		return (1);
	ptr = a.head;
	while (ptr != NULL)
	{
		printf("ptr = <%d>size <%d>\n", ptr->x, a.size);
		ptr = ptr->next;
	}
	printf("***sortie stack_a***\n\n");
	turk_algo(&a, &b);
	return (0);
}
