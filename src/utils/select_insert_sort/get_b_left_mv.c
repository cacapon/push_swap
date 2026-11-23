/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_left_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 08:03:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * stack_bに対してvalueを挿入するのに必要な左方向のシフト回数を取得します。
 *
 * @param value
 * @param b
 * @return int
 */
int	get_b_left_mv(int value, t_dll *b)
{
	t_dll_node	*node;
	size_t		i;

	if (b->size < 2)
		return (0);
	node = b->head;
	i = 0;
	while (i < b->size)
	{
		if (node->value > value && value > node->next->value)
			return ((i + 1) % b->size);
		node = node->next;
		i++;
	}
	return (b->index(b, b->max(b)));
}
