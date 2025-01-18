/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/18 17:10:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_move_count	_get_move_count_a(t_dll *stack, t_dll_node *node)
{
	t_move_count	mv;
	size_t			len;

	len = stack->len(stack);
	mv.left = stack->index(stack, node->value);
	mv.right = (len - mv.left) % len;
	return (mv);
}

/**
 * @brief スタックｂにインサートするために移動させる量を計算します
 *
 * @param stack
 * @param node
 * @return t_move_count
 * @note	見つからない場合は最小値の前の位置に移動する量を返します。
 */
static t_move_count	_get_move_count_b(t_dll *stack, t_dll_node *node)
{
	t_dll_node		*check;
	t_move_count	mv;
	const int		value = node->value;
	size_t			len;

	ft_printf("DBG:get_move_count_b:%d\n", value);

	mv = (t_move_count){.left = 0, .right = 0};
	len = stack->len(stack);
	if (len <= 1)
		return (mv);
	check = stack->head;
	while (check)
	{
		mv.left++;
		if (check->value > value && value > check->next->value)
			break ;
		check = check->next;
		if (check == stack->head)
		{
			mv.left = stack->index(stack, stack->min(stack)) + 1;
			break ;
		}
	}
	mv.right = (len - mv.left) % len;
	ft_printf("\tmv(<%d,%d>)\n",mv.left, mv.right);
	return (mv);
}

static t_move_cmd	_get_min_move(t_move_count mv_a, t_move_count mv_b)
{
	t_move_cmd	result;

	result = (t_move_cmd){.a_l = 0, .a_r = 0, .b_l = 0, .b_r = 0};
	if (mv_a.right < mv_a.left)
		result.a_r += mv_a.right;
	else
		result.a_l += mv_a.left;
	if (mv_b.right < mv_b.left)
		result.b_r += mv_b.right;
	else
		result.b_l += mv_b.left;
	return (result);
}

static size_t	_get_min_cmd_index(t_move_cmd *mv, size_t len)
{
	size_t	i;
	size_t	mv_min;
	size_t	mv_min_i;
	size_t	total;

	i = 0;
	mv_min = ULONG_MAX;
	mv_min_i = 0;
	while (i < len)
	{
		total = mv[i].a_l + mv[i].a_r + mv[i].b_l + mv[i].b_r;
		if (total < mv_min)
		{
			mv_min = total;
			mv_min_i = i;
		}
		i++;
	}
	return (mv_min_i);
}

void	select_insert_sort(t_dll *stack_a, t_dll *stack_b)
{
	size_t		index;
	t_move_cmd	*mv;
	t_dll_node	*node;
	size_t		cmd_i;
	size_t		len;

	while (stack_a->head)
	{
		len = stack_a->len(stack_a);
		node = stack_a->head;
		index = 0;
		mv = ft_calloc(len, sizeof(t_move_cmd));
		if (!mv)
			exit(1);
		while (index < len)
		{
			mv[index] = _get_min_move(_get_move_count_a(stack_a, node),
					_get_move_count_b(stack_b, node));
			ft_printf("min_mv=a(<%d | %d>) ", mv[index].a_l, mv[index].a_r);
			ft_printf("min_mv=b(<%d | %d>)\n", mv[index].b_l, mv[index].b_r);
			node = node->next;
			index++;
		}
		cmd_i = _get_min_cmd_index(mv, len);
		ft_printf("---\ncmd_mv=a(<%d | %d>) ", mv[cmd_i].a_l, mv[cmd_i].a_r);
		ft_printf("cmd_mv=b(<%d | %d>)\n---\n", mv[cmd_i].b_l, mv[cmd_i].b_r);
		while (mv[cmd_i].a_l || mv[cmd_i].a_r || mv[cmd_i].b_l || mv[cmd_i].b_r)
		{
			if (mv[cmd_i].a_l && mv[cmd_i].a_l--)
				rra(stack_a);
			if (mv[cmd_i].a_r && mv[cmd_i].a_r--)
				ra(stack_a);
			if (mv[cmd_i].b_l && mv[cmd_i].b_l--)
				rrb(stack_b);
			if (mv[cmd_i].b_r && mv[cmd_i].b_r--)
				rb(stack_b);
		}
		pb(stack_b, stack_a);
		free(mv);
	}
	while (stack_b->head)
		pa(stack_a, stack_b);
	// DBG
	index = 0;
	node = stack_a->head;
	while (index < stack_a->len(stack_a))
	{
		ft_printf("%d,",node->value);
		node = node->next;
		index++;
	}
	ft_printf("\n");
}
