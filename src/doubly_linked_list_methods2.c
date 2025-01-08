/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_methods2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/08 11:49:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief valueがDLLの中にあるか調べます
 *
 * @param self
 * @param value
 * @return int : 0:存在しない 1:存在する
 * @note :pre self != NULL
 */
int	is_in(t_dll *self, int value)
{
	size_t		i;
	t_dll_node	*node;

	i = 0;
	node = self->head;
	while (i < self->size)
	{
		if (value == node->value)
			return (1);
		node = node->next;
		i++;
	}
	return (0);
}
