/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:55:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストの中身をクリアしてNULLをセットします
 *
 * @param self
 */
void	free_dll(t_dll **self)
{
	t_dll_node	*node;
	t_dll_node	*next;
	t_dll_node	*start;

	if (!self || !(*self))
		return ;
	node = (*self)->head;
	start = node;
	while (node)
	{
		next = node->next;
		free(node);
		if (next == start)
			break ;
		node = next;
	}
	free(*self);
	*self = NULL;
}
