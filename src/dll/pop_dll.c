/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 16:23:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストの先頭要素を取り出します
 * 
 * @param self 
 * @return t_dll_node*
 * @note	ノードが無い場合はNULLを返します
 */
t_dll_node	*pop_dll(t_dll *self)
{
	t_dll_node	*node;

	if (!self->head)
		return (NULL);
	node = self->head;
	self->head = self->head->next;
	self->head->prev = self->tail;
	node->prev = node;
	node->next = node;
	return (node);
}
