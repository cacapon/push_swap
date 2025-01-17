/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 15:01:09 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_get_min_index(t_dll *stack, t_dll_direction dir)
{
	int			min;
	int			index;
	int			min_index;
	t_dll_node	*node;

	index = 0;
	min_index = -1;
	min = INT_MAX;
	node = stack->head;
	while (1)
	{
		if (node->value < min)
		{
			min = node->value;
			min_index = index;
		}
		if (dir == DLL_SHIFT_UP)
			node = node->prev;
		else
			node = node->next;
		if (node == stack->head)
			break ;
		index++;
	}
	return (min_index);
}

void	select_sort(t_dll *stack_a, t_dll *stack_b)
{
	int	min_index_l;
	int	min_index_r;

	while (stack_a->head)
	{
		min_index_r = _get_min_index(stack_a, DLL_SHIFT_DOWN);
		min_index_l = _get_min_index(stack_a, DLL_SHIFT_UP);
		if (min_index_r < min_index_l)
			ra(stack_a);
		else
			rra(stack_a);
		pb(stack_b, stack_a);
	}
	while (stack_b->head)
		pa(stack_a, stack_b);
}
