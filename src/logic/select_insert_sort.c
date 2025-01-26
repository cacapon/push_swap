/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 14:41:55 by ttsubo           ###   ########.fr       */
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

/*
	aがなくなるまで
		xをプッシュするために必要なa,bの移動量を求める (a<,a>,b<,b>)...[0]
		[0]からコマンド用の移動量を計算...[1]:[(a<>,b<>,common<>,mv)...]
		[1]の一番小さいものを選択...[2]:(a<>,b<>,common<>,mv)
		[2]に従ってコマンドを実行する
		bにプッシュ
	bの最大値を先頭に合わせる
	aにプッシュ
*/
void	select_insert_sort(t_dll *stack_a, t_dll *stack_b)
{
	size_t		ite;
	t_cmd_mv	*cmd_moves;
	t_cmd_mv	min_mv;

	while (stack_a->size > 5)
	{
		ite = 0;
		cmd_moves = ft_calloc(stack_a->size, sizeof(t_cmd_mv));
		while (ite < stack_a->size)
		{
			cmd_moves[ite] = get_cmd_mv(ite, stack_a, stack_b);
			ite++;
		}
		min_mv = get_min_mv(cmd_moves, stack_a->size);
		exec_cmd(&stack_a, &stack_b, min_mv);
		free(cmd_moves);
	}
	short_logic(stack_a, stack_b);
	move_max_to_head(&stack_b);
	push_back_a(stack_a, stack_b);
	move_min_to_head(&stack_a);
}
