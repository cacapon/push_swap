/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:41:56 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/23 21:03:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief stackの最初の二つの要素を入れ替えます
 * 
 * @param [out] stack	: 要素を入れ替えるスタック
 * @param [in] type		: スタックの種類
 * @note 				: 要素数が1以下の場合は操作しません
 */
void swap(int *stack, t_stack_type type)
{
	(void) stack;
	(void) type;
}

/**
 * @brief from -> toへスタックの先頭の要素を送ります
 * 
 * @param from_stack	: 送り元のスタック
 * @param to_stack		: 送り先のスタック
 * @param type			: スタックの種類
 * @note				: fromが空の場合は操作しません
 */
void push(int *from_stack, int *to_stack, t_stack_type type)
{
	(void) from_stack;
	(void) to_stack;
	(void) type;
}

/**
 * @brief スタックを１つずつシフトアップします。最初の要素が最後の要素になります。
 * 
 * @param stack		: シフトアップするスタック
 * @param type		: スタックの種類
 */
void rotate(int *stack, t_stack_type type)
{
	(void) stack;
	(void) type;
}

/**
 * @brief スタックを１つずつシフトダウンします。最後の要素が最初の要素になります。
 * 
 * @param stack		: シフトアップするスタック
 * @param type		: スタックの種類
 */
void rv_rotate(int *stack, t_stack_type type)
{
	(void) stack;
	(void) type;
}