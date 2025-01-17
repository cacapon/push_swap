/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 21:53:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

/**
 * @brief 双方向リストを初期化して、メソッドをセットします。
 * 
 * @return t_dll* 
 */
t_dll	*init_dll(void)
{
	t_dll	*dll;

	dll = (t_dll *)ft_calloc(sizeof(t_dll), 1);
	if (!dll)
		return (NULL);
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
	dll->add = add_dll;
	dll->append = append_dll;
	dll->pop = pop_dll;
	dll->swap = swap_dll;
	dll->rotate = rotate_dll;
	dll->free = free_dll;
	dll->is_in = is_in;
	dll->index = index_dll;
	dll->max = max_dll;
	dll->min = min_dll;
	dll->get = get_dll;
	return (dll);
}
