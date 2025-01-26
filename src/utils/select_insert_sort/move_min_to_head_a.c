/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_to_head_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 16:24:04 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_head_a(t_dll **a)
{
	int			cmd_mv;
	int			a_min_mv[2];

	a_min_mv[0] = get_a_left_mv((*a)->min(*a), *a);
	a_min_mv[1] = ((*a)->size - a_min_mv[0]) % (*a)->size;
	if (a_min_mv[0] < a_min_mv[1])
		cmd_mv = (-a_min_mv[0]);
	else
		cmd_mv = (a_min_mv[1]);
	while (cmd_mv != 0)
	{
		if (cmd_mv > 0 && cmd_mv--)
			rra(*a);
		else if (cmd_mv < 0 && cmd_mv++)
			ra(*a);
	}
}
