/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_mv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 07:31:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void _set_mv_a_count(int ite, int mv_a[2], t_dll *a) {
  if (a->size == 0) {
    mv_a[0] = 0;
    mv_a[1] = 0;
    return;
  }
  mv_a[0] = ite;
  mv_a[1] = (a->size - mv_a[0]) % a->size;
}

static void _set_mv_b_count(int value, int mv_b[2], t_dll *b) {
  if (b->size == 0) {
    mv_b[0] = 0;
    mv_b[1] = 0;
    return;
  }
  mv_b[0] = get_b_left_mv(value, b);
  mv_b[1] = (b->size - mv_b[0]) % b->size;
}

static t_cmd_mv _set_result(int mv_a[2], int mv_b[2]) {
  t_cmd_mv result;
  int cost[4];
  int best;

  cost[0] = ft_max(mv_a[0], mv_b[0]);
  cost[1] = ft_max(mv_a[1], mv_b[1]);
  cost[2] = mv_a[0] + mv_b[1];
  cost[3] = mv_a[1] + mv_b[0];

  best = 0;
  if (cost[1] < cost[best])
    best = 1;
  if (cost[2] < cost[best])
    best = 2;
  if (cost[3] < cost[best])
    best = 3;

  result = (t_cmd_mv){0};
  if (best == 0)
    result.c = -ft_min(mv_a[0], mv_b[0]);
  else if (best == 1)
    result.c = ft_min(mv_a[1], mv_b[1]);
  if (best == 0 || best == 2)
    result.a = -mv_a[0] - result.c;
  else
    result.a = mv_a[1] - result.c;

  if (best == 0 || best == 3)
    result.b = -mv_b[0] - result.c;
  else
    result.b = mv_b[1] - result.c;
  result.total = cost[best];
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
t_cmd_mv get_cmd_mv(size_t ite, int value, t_dll *a, t_dll *b) {
  int mv_a[2];
  int mv_b[2];
  t_cmd_mv result;

  _set_mv_a_count(ite, mv_a, a);
  _set_mv_b_count(value, mv_b, b);
  result = _set_result(mv_a, mv_b);
  return (result);
}
