/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 21:32:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief bの先頭の要素を取り出してaの先頭に置きます。
 *
 * @param stack_a
 * @param stack_b
 */
static void	_push_a(t_dll *stack_a, t_dll *stack_b)
{
	t_dll_node	*pop_node;

	ft_printf("pa\n");
	pop_node = stack_b->pop(stack_b);
	if (!pop_node)
		return ;
	stack_a->add(stack_a, pop_node->value);
	free(pop_node);
}

/**
 * @brief aの先頭の要素を取り出してbの先頭に置きます
 *
 * @param stack_b
 * @param stack_a
 */
static void	_push_b(t_dll *stack_b, t_dll *stack_a)
{
	t_dll_node	*pop_node;

	ft_printf("pb\n");
	pop_node = stack_a->pop(stack_a);
	if (!pop_node)
		return ;
	stack_b->add(stack_b, pop_node->value);
	free(pop_node);
}

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

static void _rotate(t_dll *stack_a, t_dll_direction dir, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (dir == DLL_SHIFT_UP)
			ft_printf("ra\n");
		else
			ft_printf("rra\n");
		stack_a->rotate(stack_a, dir);
		i++;
	}
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
			_rotate(stack_a, DLL_SHIFT_UP, min_index_r);
		else
			_rotate(stack_a, DLL_SHIFT_DOWN, min_index_l);
		_push_b(stack_b, stack_a);
	}
	while (stack_b->head)
		_push_a(stack_a, stack_b);
}
