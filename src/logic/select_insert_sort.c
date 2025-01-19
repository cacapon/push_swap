/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 20:23:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct e_cmd_mv
{
	int		a;
	int		b;
	int		c;
	int		total;
}			t_cmd_mv;

int	get_b_left_mv(int value, t_dll *b)
{
	int		mv;
	size_t	i;
	size_t	i_nx;

	mv = 0;
	if (b->len(b) < 2)
		return (mv);
	i = 0;
	while (i < b->len(b))
	{
		i_nx = (i + 1) % b->len(b);
		if (b->get(b, i) > value && value > b->get(b, i_nx))
			return (i_nx);
		i++;
	}
	return (b->index(b, b->max(b)));
}

/**
 * @brief a,bの移動量を求めてから実際に動かすコマンドの移動数を求めます。
 *
 * @param ite
 * @param a
 * @param b
 * @return t_cmd_mv
 * @note	TODO:分割できそう
 * @note	a,b移動量取得→最小の動きを求める→resultにセットする
 */
t_cmd_mv	get_cmd_mv(size_t ite, t_dll *a, t_dll *b)
{
	int			mv_a[2];
	int			mv_b[2];
	t_cmd_mv	result;

	result = (t_cmd_mv){.a = 0, .b = 0, .c = 0, .total = 0};
	mv_a[0] = a->index(a, a->get(a, ite));
	mv_a[1] = (a->len(a) - mv_a[0]) % a->len(a);
	mv_b[0] = get_b_left_mv(a->get(a, ite), b);
	mv_b[1] = (b->len(b) - mv_b[0]) % b->len(b);
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

t_cmd_mv	get_min_mv(t_cmd_mv *cmd_moves, size_t size)
{
	size_t	index;
	size_t	min_i;
	int		min_mv;

	min_mv = INT_MAX;
	index = 0;
	min_i = 0;
	while (index < size)
	{
		if (cmd_moves[index].total < min_mv)
		{
			min_mv = cmd_moves[index].total;
			min_i = index;
		}
		index++;
	}
	return (cmd_moves[min_i]);
}

int	get_b_max_mv(t_dll *b)
{
	int			b_max_mv[2];

	b_max_mv[0] = get_b_left_mv(b->max(b), b);
	b_max_mv[1] = (b->len(b) - b_max_mv[0]) % b->len(b);
	if (b_max_mv[0] < b_max_mv[1])
		return (-b_max_mv[0]);
	else
		return (b_max_mv[1]);
}

void	exec_cmd(t_dll **a, t_dll **b, t_cmd_mv cmd)
{
	while (cmd.a != 0 || cmd.b != 0 || cmd.c != 0)
	{
		if (cmd.c < 0 && cmd.c++)
			rr(*a, *b);
		else if (cmd.c > 0 && cmd.c--)
			rrr(*a, *b);
		else if (cmd.a < 0 && cmd.a++)
			ra(*a);
		else if (cmd.a > 0 && cmd.a--)
			rra(*a);
		else if (cmd.b < 0 && cmd.b++)
			rb(*b);
		else if (cmd.b > 0 && cmd.b--)
			rrb(*b);
	}
	pb(*b, *a);
}

static void	show(t_dll *dll)
{
	t_dll_node	*node;

	node = dll->head;
	ft_printf("DEBUG:[");
	while (node)
	{
		ft_printf("%d,", node->value);
		node = node->next;
		if (node == dll->head)
			break ;
	}
	ft_printf("]\n");
}

static void	debug_show(t_cmd_mv *mvs, size_t size)
{
	size_t	i;

	i = 0;
	ft_printf("DEBUG:cmd_mvs:[");
	while (i < size)
	{
		ft_printf("[%d,%d,%d,%d], ", mvs[i].a, mvs[i].b, mvs[i].c,
			mvs[i].total);
		i++;
	}
	ft_printf("]\n");
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
	int			max_b_mv;

	while (stack_a->head)
	{
		ite = 0;
		cmd_moves = ft_calloc(stack_a->len(stack_a), sizeof(t_cmd_mv));
		while (ite < stack_a->len(stack_a))
		{
			cmd_moves[ite] = get_cmd_mv(ite, stack_a, stack_b);
			ite++;
		}
		debug_show(cmd_moves, stack_a->len(stack_a));
		min_mv = get_min_mv(cmd_moves, stack_a->len(stack_a));
		exec_cmd(&stack_a, &stack_b, min_mv);
		free(cmd_moves);
	}
	max_b_mv = get_b_max_mv(stack_b);
	while (max_b_mv != 0)
	{
		if (max_b_mv > 0 && max_b_mv--)
			rrb(stack_b);
		else if (max_b_mv < 0 && max_b_mv++)
			rb(stack_b);
	}
	while (stack_b->head)
		pa(stack_a, stack_b);
}
