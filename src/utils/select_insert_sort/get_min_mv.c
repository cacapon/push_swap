/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_mv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 20:49:50 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd_mv	get_min_mv(t_cmd_mv *cmd_moves, size_t size)
{
	size_t	index;
	size_t	min_i;
	int		min_mv;

	min_mv = INT_MAX;
	index = 0;
	min_i = 0;
	while (index < size)
	{
		if (cmd_moves[index].total < min_mv)
		{
			min_mv = cmd_moves[index].total;
			min_i = index;
		}
		index++;
	}
	return (cmd_moves[min_i]);
}
