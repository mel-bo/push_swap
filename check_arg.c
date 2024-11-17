/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:34:23 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/07 14:45:13 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char **s)
{
	int	i;
	int	j;

	i = 0;
	printf("*****isdigit*****\n");
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (j == 0 && (s[i][j] == '-' || s[i][j] == '+'))
				j++;
			if (s[i][j] < '0' || s[i][j] > '9')
				return (1);
			j++;
		}
		printf("%s\n", s[i]);
		i++;
	}
	printf("***sortie isdigit***\n\n");
	return (0);
}

int	limit(char **tab, stack *a)
{
	int		i;
	long	n;
	
	i = 0;
	printf("********limit********\n");
	while (tab[i])
	{
		n = ft_atol(tab[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		enqueue(a, n);
		i++;
	}
	printf("*****sortie limit*****\n\n");
	return (0);
}
/* rajouter la verification pour voir si tt est en ordre */
int	check_double(stack *a)
{
	node	*value;
	node	*base;
	
	printf("******check_double******\n"); // effecer
	base = malloc(sizeof(node));
	if (!base)
		return (1);
	base = a->tail;
	value = malloc(sizeof(node));
	if (!value)
		return (1);
	while (base != NULL)
	{
		value = base->preview;
		while (value != NULL)
		{
			if (base->x == value->x)
				return (1);
			value = value->preview;
		}
		base = base->preview;
	}
	printf("*****sortie double*****\n\n"); // effacer
	free(base);
	free(value);
	return (0);
}

int	parser(char **tab, stack *a)
{
	if (ft_isdigit(tab))
		return (1);
	if (limit(tab, a))
		return (1);
	if (check_double(a))
		return (1);
	return (0);
}
