/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_to_head.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/24 16:44:58 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_head(t_dll **s)
{
	int			cmd_mv;
	int			s_min_mv[2];

	s_min_mv[0] = get_a_left_mv((*s)->min(*s), *s);
	s_min_mv[1] = ((*s)->size - s_min_mv[0]) % (*s)->size;
	if (s_min_mv[0] < s_min_mv[1])
		cmd_mv = (-s_min_mv[0]);
	else
		cmd_mv = (s_min_mv[1]);
	while (cmd_mv != 0)
	{
		if (cmd_mv > 0 && cmd_mv--)
			rra(*s);
		else if (cmd_mv < 0 && cmd_mv++)
			ra(*s);
	}
}
