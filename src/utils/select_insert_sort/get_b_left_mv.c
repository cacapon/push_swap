/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_left_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 21:46:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief stack_bに対してvalueを挿入するのに必要な左方向のシフト回数を取得します。
 * 
 * @param value 
 * @param b 
 * @return int 
 */
int	get_b_left_mv(int value, t_dll *b)
{
	int		mv;
	size_t	i;
	size_t	i_nx;

	mv = 0;
	if (b->size < 2)
		return (mv);
	i = 0;
	while (i < b->size)
	{
		i_nx = (i + 1) % b->size;
		if (b->get(b, i) > value && value > b->get(b, i_nx))
			return (i_nx);
		i++;
	}
	return (b->index(b, b->max(b)));
}
