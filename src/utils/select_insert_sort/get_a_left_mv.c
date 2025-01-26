/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_left_mv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/24 16:39:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief stack_aに対してvalueを挿入するのに必要な左方向のシフト回数を取得します。
 * 
 * @param value 
 * @param a 
 * @return int 
 */
int	get_a_left_mv(int value, t_dll *a)
{
	int		mv;
	size_t	i;
	size_t	i_nx;

	mv = 0;
	if (a->size < 2)
		return (mv);
	i = 0;
	while (i < a->size)
	{
		i_nx = (i + 1) % a->size;
		if (a->get(a, i) < value && value < a->get(a, i_nx))
			return (i_nx);
		i++;
	}
	return (a->index(a, a->min(a)));
}
