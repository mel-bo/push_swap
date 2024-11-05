/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:10:42 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/03 15:11:13 by mel-bout         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc < 2 || argv[1][0] == '\0')
		return (ft_printf("Error\n"), 1);
	//call_split(argv);
	if (parsor(argv, argc))
		return (ft_printf("Error\n"), 1);
	return (0);
}
