/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:29:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_dll *stack_a)
{
	int	tmp;

	ft_printf("sa\n");
	if (!stack_a)
		return ;
	tmp = stack_a->head->value;
	stack_a->head->value = stack_a->head->next->value;
	stack_a->head->next->value = tmp;
}

static void	_rotate_a(t_dll *stack_a)
{
	ft_printf("ra\n");
	stack_a->rotate(stack_a, DLL_SHIFT_UP);
}

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

void	select_sort(t_dll *stack_a, t_dll *stack_b)
{
	int	min_index_l;
	int min_index_r;
	
	// stack_aがカラになるまで
		// 左右の最小値の位置を探す
		// 短い方にrotateする
		// bにプッシュ
	// aにプッシュ
	while (stack_a->head)

}
