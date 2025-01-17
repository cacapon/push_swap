/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 15:35:08 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストのノードの最小値を返します。
 * 
 * @param self 
 * @return int
 * @note	見つからない場合はINT_MAXを返します。
 */
int	min_dll(t_dll *self)
{
	t_dll_node	*node;
	int		min;

	min = INT_MAX;
	if (!self || !self->head)
		return (min);
	node = self->head;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
		if (node == self->head)
			break;
	}
	return (min);
}
