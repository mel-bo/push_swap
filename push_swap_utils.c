/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bout <mel-bout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:17:00 by mel-bout          #+#    #+#             */
/*   Updated: 2024/11/03 15:05:19 by mel-bout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // effacer

// void	stack_a(Node **root, int value)
// {
// 	Node	*new_node;
// 	Node	*curr;

// 	new_node = malloc(sizeof(Node));
// 	if (!new_node)
// 		return ;
// 	new_node->next = NULL;
// 	new_node->x = value;
// 	if (*root == NULL)
// 	{
// 		*root =  new_node;
// 		return ;
// 	}
// 	printf("before seconde node\n");
// 	curr = *root;
// 	while (curr->next != NULL)
// 		curr = curr->next;
// 	curr->next = new_node;
// }
// int main(void)
// {
// 	Node	*root;
// 	Node	*curr;
	
// 	root = NULL;
// 	curr = root;
// 	stack_a(&root, 5);
// 	stack_a(&root, 42);
// 	while (curr != NULL)
// 	{
// 		printf("%d\n", curr->x);
// 		curr = curr->next;
// 	}
// 	return (0);
// }

