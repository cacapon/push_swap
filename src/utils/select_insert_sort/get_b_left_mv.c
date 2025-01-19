/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_b_left_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 20:49:49 by ttsubo           ###   ########.fr       */
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
	if (b->len(b) < 2)
		return (mv);
	i = 0;
	while (i < b->len(b))
	{
		i_nx = (i + 1) % b->len(b);
		if (b->get(b, i) > value && value > b->get(b, i_nx))
			return (i_nx);
		i++;
	}
	return (b->index(b, b->max(b)));
}
