/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_dll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:57:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 15:04:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief ノードが昇順にソートされているかを返します。
 * 
 * @param self 
 * @retval 0: 未ソート
 * @retval 1: ソート済 
 * @note TODO	降順は未対応
 */
int	is_sorted_dll(t_dll *self)
{
	t_dll_node	*node;

	if (self->size <= 1)
		return (1);
	node = self->head;
	while (node)
	{
		if (node->value >= node->next->value)
			return (0);
		node = node->next;
		if (node->next == self->head)
			break ;
	}
	return (1);
}
