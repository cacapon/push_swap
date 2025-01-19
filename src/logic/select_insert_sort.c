/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 20:56:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	while (stack_a->head)
	{
		ite = 0;
		cmd_moves = ft_calloc(stack_a->len(stack_a), sizeof(t_cmd_mv));
		while (ite < stack_a->len(stack_a))
		{
			cmd_moves[ite] = get_cmd_mv(ite, stack_a, stack_b);
			ite++;
		}
		min_mv = get_min_mv(cmd_moves, stack_a->len(stack_a));
		exec_cmd(&stack_a, &stack_b, min_mv);
		free(cmd_moves);
	}
	move_max_to_head(&stack_b);
	while (stack_b->head)
		pa(stack_a, stack_b);
}
