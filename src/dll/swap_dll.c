/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 16:23:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 先頭と２番目のノードの中身を交換します
 * 
 * @param self 
 * @note	ノード数が1の場合は動作しますが実質意味がありません
 * @note	ノードがない場合は何もしません。
 */
void	swap_dll(t_dll *self)
{
	int	tmp;

	if (!self || !self->head || !self->head->next)
		return ;
	tmp = self->head->value;
	self->head->value = self->head->next->value;
	self->head->next->value = tmp;
}
