/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_mv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 21:47:43 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_set_mv_a_count(int ite, int mv_a[2], t_dll *a)
{
	mv_a[0] = a->index(a, a->get(a, ite));
	mv_a[1] = (a->size - mv_a[0]) % a->size;
}

static void	_set_mv_b_count(int ite, int mv_b[2], t_dll *a, t_dll *b)
{
	mv_b[0] = get_b_left_mv(a->get(a, ite), b);
	mv_b[1] = (b->size - mv_b[0]) % b->size;
}

static t_cmd_mv	_set_result(int mv_a[2], int mv_b[2])
{
	t_cmd_mv	result;

	result = (t_cmd_mv){.a = 0, .b = 0, .c = 0, .total = 0};
	if (mv_a[0] < mv_a[1])
		result.a = -mv_a[0];
	else
		result.a = mv_a[1];
	if (mv_b[0] < mv_b[1])
		result.b = -mv_b[0];
	else
		result.b = mv_b[1];
	if (result.a > 0 && result.b > 0)
		result.c = ft_min(result.a, result.b);
	else if (result.a < 0 && result.b < 0)
		result.c = ft_max(result.a, result.b);
	result.a -= result.c;
	result.b -= result.c;
	result.total = ft_abs(result.a) + ft_abs(result.b) + ft_abs(result.c);
	return (result);
}

/**
 * @brief a,bの移動量を求めてから実際に動かすコマンドの移動数を求めます。
 *
 * @param ite
 * @param a
 * @param b
 * @return t_cmd_mv
 */
t_cmd_mv	get_cmd_mv(size_t ite, t_dll *a, t_dll *b)
{
	int			mv_a[2];
	int			mv_b[2];
	t_cmd_mv	result;

	_set_mv_a_count(ite, mv_a, a);
	_set_mv_b_count(ite, mv_b, a, b);
	result = _set_result(mv_a, mv_b);
	return (result);
}
