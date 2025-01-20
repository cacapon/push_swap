/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:21:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/16 16:39:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rotate(t_dll *stack, t_dll_direction dir)
{
	stack->rotate(stack, dir);
}

/**
 * @brief aをシフトアップします。
 * 
 * @param stack_a
 * @note 10-20-30 -> 20-30-10 
 */
void	ra(t_dll *stack_a)
{
	ft_printf("ra\n");
	_rotate(stack_a, DLL_SHIFT_UP);
}

/**
 * @brief bをシフトアップします。
 * 
 * @param stack_b 
 * @note 10-20-30 -> 20-30-10 
 */
void	rb(t_dll *stack_b)
{
	ft_printf("rb\n");
	_rotate(stack_b, DLL_SHIFT_UP);
}

/**
 * @brief a,bをシフトアップします
 * 
 * @param stack_a 
 * @param stack_b 
 * @note 10-20-30 -> 20-30-10 
 */
void	rr(t_dll *stack_a, t_dll *stack_b)
{
	ft_printf("rr\n");
	_rotate(stack_a, DLL_SHIFT_UP);
	_rotate(stack_b, DLL_SHIFT_UP);
}
