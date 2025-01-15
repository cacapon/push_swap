/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 17:21:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストの先頭にノードを追加します
 * 
 * @param self 
 * @param value
 */
void	add_dll(t_dll *self, int value)
{
	t_dll_node	*node;

	node = (t_dll_node *)ft_calloc(sizeof(t_dll_node), 1);
	node->value = value;
	if (!self->head)
	{
		self->head = node;
		self->tail = node;
	}
	node->next = self->head;
	node->prev = self->tail;
	self->head->prev = node;
	self->tail->next = node;
	self->head = node;
}
