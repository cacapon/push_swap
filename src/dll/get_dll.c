/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 13:43:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストのheadからindex番目の値を取得します
 * 
 * @param self 
 * @param index 
 * @return int
 * @note	双方向リスト内にノードが無い場合は0を返します。
 * @note	len(t_dll)-1 < indexの場合も0を返します。
 */
int	get_dll(t_dll *self, size_t index)
{
	size_t		ite;
	t_dll_node	*node;

	if (!self || !self->head)
		return (0);
	ite = 0;
	node = self->head;
	while (ite <= index)
	{
		if (ite++ == index)
			return (node->value);
		node = node->next;
	}
	return (0);
}
