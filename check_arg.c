/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:34:23 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/03 15:13:48 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char **s)
{
	int	i;
	int	j;

	i = 1;
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
	printf("sortie isdigit\n");
	return (0);
}

int	limit(char **tab)
{
	int		i;
	long	n;
	
	i = 0;
	while (tab[i])
	{
		n = ft_atol(tab[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_double(char **tab, int x)
{
	
}

int	parsor(char **tab, int x)
{
	if (ft_isdigit(tab))
		return (1);
	if (limit(tab))
		return (1);
	if (check_double(tab, x))
		return (1);
	return (0);
}
