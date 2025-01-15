/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 17:42:09 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_dll *stack_a)
{
	int	tmp;

	printf("sa\n");
	if (!stack_a)
		return ;
	tmp = stack_a->head->value;
	stack_a->head->value = stack_a->head->next->value;
	stack_a->head->next->value = tmp;
}

static void	_rotate_a(t_dll *stack_a)
{
	printf("ra\n");
	stack_a->rotate(stack_a, DLL_SHIFT_UP);
}

static int	_is_ascending(t_dll *dll)
{
	t_dll_node	*node;

	node = dll->head;
	while (node)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		if (node == dll->head)
			break ;
	}
	return (1);
}

void	bubble_sort(t_dll *stack_a)
{
	while (_is_ascending(stack_a))
	{
		if (stack_a->head->value > stack_a->head->next->value)
			_swap(stack_a);
		_rotate_a(stack_a);
	}
}
