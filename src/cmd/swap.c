/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:21:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/18 15:04:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap(t_dll *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = tmp;
}

/**
 * @brief stack_aの最初の二つの要素を入れ替えます
 *
 * @param [out] stack	: 要素を入れ替えるスタック
 * @param [in] type		: スタックの種類
 * @note 				: 要素数が1以下の場合は操作しません
 */
void	sa(t_dll *stack_a)
{
	ft_printf("sa\n");
	_swap(stack_a);
}

/**
 * @brief stack_bの最初の二つの要素を入れ替えます
 *
 * @param [out] stack	: 要素を入れ替えるスタック
 * @param [in] type		: スタックの種類
 * @note 				: 要素数が1以下の場合は操作しません
 */
void	sb(t_dll *stack_b)
{
	ft_printf("sb\n");
	_swap(stack_b);
}

/**
 * @brief 両方のスタックの最初の要素を入れ替えます。
 *
 * @param stack_a
 * @param stack_b
 */
void	ss(t_dll *stack_a, t_dll *stack_b)
{
	ft_printf("ss\n");
	_swap(stack_a);
	_swap(stack_b);
}
