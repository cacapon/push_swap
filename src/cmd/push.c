/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:21:09 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/18 15:04:31 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_push(t_dll *dst, t_dll *src)
{
	t_dll_node	*pop_node;

	pop_node = src->pop(src);
	if (!pop_node)
		return ;
	dst->add(dst, pop_node->value);
	free(pop_node);
}

/**
 * @brief b->aにプッシュします。
 *
 * @param stack_a
 * @param stack_b
 */
void	pa(t_dll *stack_a, t_dll *stack_b)
{
	ft_printf("pa\n");
	_push(stack_a, stack_b);
}

/**
 * @brief a->bにプッシュします。
 *
 * @param stack_b
 * @param stack_a
 */
void	pb(t_dll *stack_b, t_dll *stack_a)
{
	ft_printf("pb\n");
	_push(stack_b, stack_a);
}
