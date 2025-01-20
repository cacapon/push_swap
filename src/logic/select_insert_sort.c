/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/20 17:05:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int _calc_select_cost()
{
	
}

static int _calc_insert_cost(t_dll *b, int value)
{

}

void	select_insert_sort(t_dll *stack_a, t_dll *stack_b)
{
	size_t		ite;
	t_cmd_mv	*cmd_moves;
	t_cmd_mv	min_mv;

	while (stack_a->size > 5)
	{
		// 選択ソートの移動コストをもとめる
		// 挿入ソートの移動コストを求める
		// コストが安い方を実行する
	}
	short_logic(stack_a, stack_b);
	move_max_to_head(&stack_b);
	while (stack_b->head)
		pa(stack_a, stack_b);
}
