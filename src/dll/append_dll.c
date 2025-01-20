/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_dll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 21:43:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストの末端にノードを追加します
 *
 * @param self
 * @param value
 */
void	append_dll(t_dll *self, int value)
{
	t_dll_node	*node;

	node = (t_dll_node *)ft_calloc(sizeof(t_dll_node), 1);
	node->value = value;
	if (!self->head)
	{
		self->head = node;
		self->tail = node;
	}
	self->head->prev = node;
	node->next = self->head;
	self->tail->next = node;
	node->prev = self->tail;
	self->tail = node;
	self->size++;
}
