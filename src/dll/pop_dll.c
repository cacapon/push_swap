/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 21:45:10 by ttsubo           ###   ########.fr       */
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
	if (self->head == self->tail)
	{
		self->head = NULL;
		self->tail = NULL;
	}
	else
	{
		self->head = self->head->next;
		self->head->prev = self->tail;
		self->tail->next = self->head;
	}
	node->prev = node;
	node->next = node;
	self->size--;
	return (node);
}
