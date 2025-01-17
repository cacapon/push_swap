/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_dll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 14:43:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストのノードの個数を返します。
 * 
 * @param self 
 * @return size_t 
 */
size_t	len_dll(t_dll *self)
{
	t_dll_node	*node;
	size_t		count;

	count = 0;
	if (!self || !self->head)
		return (count);
	node = self->head;
	while (node)
	{
		count++;
		node = node->next;
		if (node == self->head)
			break;
	}
	return (count);
}
