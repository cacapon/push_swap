/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 14:33:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストのノードの最大値を返します。
 *
 * @param self
 * @return int
 * @note	見つからない場合はINT_MINを返します。
 */
int	max_dll(t_dll *self)
{
	t_dll_node	*node;
	int			max;

	max = INT_MIN;
	if (!self || !self->head)
		return (max);
	node = self->head;
	while (node)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
		if (node == self->head)
			break ;
	}
	return (max);
}
