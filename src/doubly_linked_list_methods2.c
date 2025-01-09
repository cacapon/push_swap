/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_methods2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/09 21:58:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief valueがDLLの中にあるか調べます
 *
 * @param self
 * @param value
 * @return int : 0:存在しない 1:存在する
 */
int	is_in(t_dll *self, int value)
{
	t_dll_node	*node;
	t_dll_node	*start;

	if (!self)
		return (0);
	node = self->head;
	start = node;
	while (node)
	{
		if (value == node->value)
			return (1);
		node = node->next;
		if (node == start)
			break;
	}
	return (0);
}
