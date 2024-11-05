/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:33:12 by mel-bout          #+#    #+#             */
/*   Updated: 2024/10/27 18:37:30 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> // vv

void	*ft_free(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
		free((*tab)[i++]);
	free((*tab));
	(*tab) = NULL;
	return (NULL);
}

char	*ft_fill(char *str, char sep)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	i--;
	while (i >= 0)
	{
		s[i] = str[i];
		i--;
	}
	return (s);
}

char	**fill_tab(char *str, char sep, char **tab)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] && str[i] != sep)
		{
			tab[y] = ft_fill(str + i, sep);
			if (!tab[y])
				return (ft_free(&tab));
			y++;
		}
		while (str[i] && str[i] != sep)
			i++;
	}
	tab[y] = NULL;
	return (tab);
}

char	**ft_split(char *str, char separator)
{
	int		count;
	char	**tab;

	if (!str)
		return (NULL);
	count = words_count(str, separator);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab = fill_tab(str, separator, tab);
	if (!tab)
		return (ft_free(&tab));
	return (tab);
}

// int main(void)
// {
// 	char	*s;
// 	char	**tab;
// 	int i;

// 	i = 0;
// 	s = "32 2 35";
// 	tab = ft_split(s, ' ');
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
