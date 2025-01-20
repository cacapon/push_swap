/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_max_to_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 21:48:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_max_to_head(t_dll **b)
{
	int			cmd_mv;
	int			b_max_mv[2];

	b_max_mv[0] = get_b_left_mv((*b)->max(*b), *b);
	b_max_mv[1] = ((*b)->size - b_max_mv[0]) % (*b)->size;
	if (b_max_mv[0] < b_max_mv[1])
		cmd_mv = (-b_max_mv[0]);
	else
		cmd_mv = (b_max_mv[1]);
	while (cmd_mv != 0)
	{
		if (cmd_mv > 0 && cmd_mv--)
			rrb(*b);
		else if (cmd_mv < 0 && cmd_mv++)
			rb(*b);
	}
}
