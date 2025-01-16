/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/16 16:49:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_is_ascending(t_dll *dll)
{
	t_dll_node	*node;

	node = dll->head;
	while (node && node->next != dll->head)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	bubble_sort(t_dll *stack_a)
{
	t_dll_node *head;
	t_dll_node *node;
	
	head = stack_a->head;
	while (!_is_ascending(stack_a))
	{
		while(1)
		{
			node = stack_a->head;
			if (node->next == head)
			{
				ra(stack_a);
				break;
			}
			if (node->value > node->next->value)
				sa(stack_a);
			ra(stack_a);
		}
	}
}
