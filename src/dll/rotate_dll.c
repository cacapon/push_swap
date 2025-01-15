/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_dll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 16:23:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストをdirectionの方向に回転させます
 * 
 * @param self 
 * @param direction
 * @note	ノードが無い場合は何もしません
 */
void	rotate_dll(t_dll *self, t_dll_direction direction)
{
	if (!self || !self->head || !self->tail)
		return ;
	if (direction == DLL_SHIFT_UP)
	{
		self->head = self->head->next;
		self->tail = self->tail->next;
	}
	else if (direction == DLL_SHIFT_DOWN)
	{
		self->head = self->head->prev;
		self->tail = self->tail->prev;
	}
}
