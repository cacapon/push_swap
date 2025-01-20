/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:17:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/20 14:15:32 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_dll *s, void (*sw)(t_dll *))
{
	if (s->head->value > s->head->next->value)
		sw(s);
}

/**
 * @brief 個数3の場合
 *
 * @param a
 * @note	132 -> rra sw
 * @note	213 -> sw
 * @note	231 -> rra
 * @note	312 -> ra
 * @note	321 -> sw rra
 *
 */
static void	_size3_sort(t_dll *s, void (*sw)(t_dll *), void (*rt)(t_dll *),
		void (*rrt)(t_dll *))
{
	int	n[3];

	n[0] = s->head->value;
	n[1] = s->head->next->value;
	n[2] = s->head->next->next->value;
	if (n[0] > n[1] && n[1] < n[2] && n[2] > n[0])
		sw(s);
	if (n[0] < n[1] && n[1] > n[2] && n[2] < n[0])
		rrt(s);
	if (n[0] > n[1] && n[1] < n[2] && n[2] < n[0])
		rt(s);
	if (n[0] < n[1] && n[1] > n[2] && n[2] > n[0])
	{
		rrt(s);
		sw(s);
	}
	if (n[0] > n[1] && n[1] > n[2] && n[2] < n[0])
	{
		rt(s);
		sw(s);
	}
}

// 小さい数字をプッシュして_size3_sortで並び替えして戻す
static void	_logic_size4(t_dll *a, t_dll *b)
{
	size_t	index;
	size_t	mv_min_r;
	size_t	mv_min_l;

	index = 0;
	mv_min_l = a->index(a, a->min(a));
	mv_min_r = (a->size - mv_min_l) % a->size;
	while (index < mv_min_r && index < mv_min_l)
	{
		if (mv_min_r < mv_min_l)
			rra(a);
		else
			ra(a);
		index++;
	}
	pb(b, a);
	_size3_sort(a, sa, ra, rra);
	pa(a, b);
}

static void	_logic_size5(t_dll *a, t_dll *b)
{
	size_t	index;
	size_t	mv_min_r;
	size_t	mv_min_l;

	index = 0;
	mv_min_l = a->index(a, a->min(a));
	mv_min_r = (a->size - mv_min_l) % a->size;
	while (index < mv_min_r && index < mv_min_l)
	{
		if (mv_min_r < mv_min_l)
			rra(a);
		else
			ra(a);
		index++;
	}
	pb(b, a);
	_logic_size4(a, b);
	pa(a, b);
}

void	short_logic(t_dll *a, t_dll *b)
{
	if (a->size == 2)
		_swap(a, sa);
	if (a->size == 3)
		_size3_sort(a, sa, ra, rra);
	if (a->size == 4)
		_logic_size4(a, b);
	if (a->size == 5)
		_logic_size5(a, b);
}
