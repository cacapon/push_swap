/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 08:48:27 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_back_a(t_dll *a, t_dll *b)
{
	int	a_left;
	int	a_right;

	while (b->head)
	{
		a_left = get_a_left_mv(b->head->value, a);
		a_right = (a->size - a_left) % a->size;
		if (a_left < a_right)
			while (a_left--)
				ra(a);
		else
			while (a_right--)
				rra(a);
		pa(a, b);
	}
}

static int	_check_min_mv(t_cmd_mv current, t_cmd_mv min_mv,
		size_t ite[2], t_dll *stack[2])
{
	if (current.total < min_mv.total)
		return (1);
	if (current.total > min_mv.total)
		return (0);
	return (lookahead_cost(ite[0], stack[0], stack[1])
		< lookahead_cost(ite[1], stack[0], stack[1]));
}

static t_cmd_mv	_find_best_mv(t_dll *a, t_dll *b)
{
	size_t		ite[2];
	t_dll_node	*node;
	t_cmd_mv	current;
	t_cmd_mv	best;

	node = a->head;
	best = get_cmd_mv(0, node->value, a, b);
	ite[1] = 0;
	ite[0] = 1;
	node = node->next;
	while (ite[0] < a->size)
	{
		current = get_cmd_mv(ite[0], node->value, a, b);
		if (_check_min_mv(current, best, ite, (t_dll *[2]){a, b}))
		{
			best = current;
			ite[1] = ite[0];
		}
		node = node->next;
		ite[0]++;
	}
	return (best);
}

static void	calculate_and_execute(t_dll *stack_a, t_dll *stack_b)
{
	t_cmd_mv	best;

	best = _find_best_mv(stack_a, stack_b);
	rotate_and_push_b(&stack_a, &stack_b, best);
}

/*
		aがなくなるまで
				xをプッシュするために必要なa,bの移動量を求める
   (a<,a>,b<,b>)...[0]
				[0]からコマンド用の移動量を計算...[1]:[(a<>,b<>,common<>,mv)...]
				[1]の一番小さいものを選択...[2]:(a<>,b<>,common<>,mv)
				[2]に従ってコマンドを実行する
				bにプッシュ
		bの最大値を先頭に合わせる
		aにプッシュ
*/
void	select_insert_sort(t_dll *stack_a, t_dll *stack_b)
{
	while (stack_a->size > 5)
		calculate_and_execute(stack_a, stack_b);
	short_logic(stack_a, stack_b);
	move_max_to_head_b(&stack_b);
	push_back_a(stack_a, stack_b);
	move_min_to_head_a(&stack_a);
}
