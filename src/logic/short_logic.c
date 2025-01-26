/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:17:36 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 15:50:41 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_dll *a)
{
	if (a->head->value > a->head->next->value)
		sa(a);
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
static void	_size3_sort(t_dll *a)
{
	int	n[3];

	n[0] = a->head->value;
	n[1] = a->head->next->value;
	n[2] = a->head->next->next->value;
	if (n[0] > n[1] && n[1] < n[2] && n[2] > n[0])
		sa(a);
	if (n[0] < n[1] && n[1] > n[2] && n[2] < n[0])
		rra(a);
	if (n[0] > n[1] && n[1] < n[2] && n[2] < n[0])
		ra(a);
	if (n[0] < n[1] && n[1] > n[2] && n[2] > n[0])
	{
		rra(a);
		sa(a);
	}
	if (n[0] > n[1] && n[1] > n[2] && n[2] < n[0])
	{
		ra(a);
		sa(a);
	}
}

static void	_logic_size4(t_dll *a, t_dll *b)
{
	move_min_to_head(&a);
	pb(b, a);
	_size3_sort(a);
	pa(a, b);
}

static void	_logic_size5(t_dll *a, t_dll *b)
{
	move_min_to_head(&a);
	pb(b, a);
	_logic_size4(a, b);
	pa(a, b);
}

void	short_logic(t_dll *a, t_dll *b)
{
	if (a->size == 2)
		_swap(a);
	if (a->size == 3)
		_size3_sort(a);
	if (a->size == 4)
		_logic_size4(a, b);
	if (a->size == 5)
		_logic_size5(a, b);
}
