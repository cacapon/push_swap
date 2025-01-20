/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:21:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/16 16:41:00 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rotate(t_dll *stack, t_dll_direction dir)
{
	stack->rotate(stack, dir);
}

/**
 * @brief aをシフトダウンします。
 * 
 * @param stack_a
 * @note 10-20-30 -> 30-10-20 
 */
void	rra(t_dll *stack_a)
{
	ft_printf("rra\n");
	_rotate(stack_a, DLL_SHIFT_DOWN);
}

/**
 * @brief bをシフトダウンします。
 * 
 * @param stack_b
 * @note 10-20-30 -> 30-10-20 
 */
void	rrb(t_dll *stack_b)
{
	ft_printf("rrb\n");
	_rotate(stack_b, DLL_SHIFT_DOWN);
}

/**
 * @brief a,bをシフトダウンします。
 * 
 * @param stack_a
 * @param stack_b
 * @note 10-20-30 -> 30-10-20 
 */
void	rrr(t_dll *stack_a, t_dll *stack_b)
{
	ft_printf("rrr\n");
	_rotate(stack_a, DLL_SHIFT_DOWN);
	_rotate(stack_b, DLL_SHIFT_DOWN);
}
