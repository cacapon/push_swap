/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookahead_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 07:45:26 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 08:05:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	get_min_cost(t_dll *a, t_dll *b)
{
	t_cmd_mv	cmd;
	int			min_cost;
	size_t		i;

	if (a->size == 0)
		return (0);
	min_cost = INT_MAX;
	i = 0;
	while (i < a->size)
	{
		cmd = get_cmd_mv(i, a->get(a, i), a, b);
		if (cmd.total < min_cost)
			min_cost = cmd.total;
		i++;
	}
	return (min_cost + 1);
}

int	lookahead_cost(size_t index, t_dll *a, t_dll *b)
{
	t_dll		*tmp_a;
	t_dll		*tmp_b;
	t_cmd_mv	cmd;
	int			cost;

	tmp_a = clone_stack(a);
	tmp_b = clone_stack(b);
	if (tmp_a == NULL || tmp_b == NULL)
	{
		if (tmp_a != NULL)
			tmp_a->free(&tmp_a);
		if (tmp_b != NULL)
			tmp_b->free(&tmp_b);
		return (INT_MAX);
	}
	cmd = get_cmd_mv(index, tmp_a->get(tmp_a, index), tmp_a, tmp_b);
	simulate_rotate(tmp_a, tmp_b, cmd);
	simulate_pb(tmp_a, tmp_b);
	cost = get_min_cost(tmp_a, tmp_b);
	tmp_a->free(&tmp_a);
	tmp_b->free(&tmp_b);
	return (cost);
}
