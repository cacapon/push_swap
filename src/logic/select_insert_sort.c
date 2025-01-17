/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 15:31:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	_get_insert_index(t_dll *stack_b, int value)
{
	size_t		index;
	t_dll_node	*node;

	index = 0;
	node = stack_b->head;
	while (node)
	{
		if (node->value > value && value > node->next->value)
			return (index);
		node = node->next;
		index++;
		if (node == stack_b->head)
			break ;
	}
	exit(1);
}

void	select_insert_sort(t_dll *stack_a, t_dll *stack_b)
{
	size_t	a_min_index;

	// aすべての要素の移動量の最小を見つける
		// WIP aの最小の移動量の見つけ方
			// stack_a->min(self)で最小値をゲット
			// stack_a->index(min)でminの＞向きの移動量ゲット
			// (stack_a->len(self) - a_min) % stack-a->len(self)で＜向きの移動量ゲット
		// WIP ｘに対するbの最小の移動量の見つけ方
			// target > x && x > target.next でいけそう
			// (stack_b->len(self) - index) % stack-b->len(self)で逆向きの移動量取得
		// ４つの移動量の組み合わせから最小を取得
			// TODO 同じ向きは重ねることで効率化できる
	// 全ての候補の最小移動量で最も移動量の少ないものを選択
	// その動きに沿って移動させる
	// bからaに戻す
}
