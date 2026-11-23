/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_left_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 08:03:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * stack_aに対してvalueを挿入するのに必要な左方向のシフト回数を取得します。
 *
 * @param value
 * @param a
 * @return int
 */
int	get_a_left_mv(int value, t_dll *a)
{
	t_dll_node	*node;
	size_t		i;

	if (a->size < 2)
		return (0);
	node = a->head;
	i = 0;
	while (i < a->size)
	{
		if (node->value < value && value < node->next->value)
			return ((i + 1) % a->size);
		node = node->next;
		i++;
	}
	return (a->index(a, a->min(a)));
}
