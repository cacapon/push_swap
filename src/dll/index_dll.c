/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_dll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/18 15:02:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 指定したvalueのインデックスを取得します。
 *
 * @param self
 * @param value
 * @return int
 * @note	存在しない場合-1を返します。
 */
int	index_dll(t_dll *self, int value)
{
	t_dll_node	*node;
	int			index;

	index = 0;
	if (!self || !self->head)
		return (-1);
	node = self->head;
	while (node)
	{
		if (value == node->value)
			return (index);
		index++;
		node = node->next;
		if (node == self->head)
			break ;
	}
	return (-1);
}
