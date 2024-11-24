/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:10:42 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/24 22:52:09 by mel-bout         ###   ########.fr       */
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
void	init_queue(stack *a, stack *b)
{
	a->head = NULL;
	a->tail = NULL;
	a->size = 0;
	a->value = 0;
	b->head = NULL;
	b->tail = NULL;
	b->size = 0;
	b->value = 0;
}

int	main(int argc, char **argv)
{
	stack	a;
	stack	b;

	init_queue(&a, &b);
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
		printf("ptr = <%d>\n", ptr->x);
		ptr = ptr->next;
	}
	printf("***sortie stack_a***\n\n");
	printf("*******swap_s*******\n");
	//swap_s(&a);
	ptr = a.head;
	while (ptr != NULL)
	{
		printf("ptr = <%d>\n", ptr->x);
		ptr = ptr->next;
	}
	printf("*****sortie stack_a*****\n");
	return (0);
}
