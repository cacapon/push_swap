/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 14:58:55 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "doubly_linked_list.h"

// enum
typedef enum e_stack_type
{
	STACK_A,
	STACK_B,
	STACK_BOTH,
}		t_stack_type;

typedef enum e_push_swap_err
{
	PSW_OK,
	ERR_PSW_OUTOFRANGE,
	ERR_PSW_NOT_NUM,
}		t_push_swap_err;

// prototype

int		ft_atoi_with_error(const char *str, t_push_swap_err *error);
void	pa(t_dll *stack_a, t_dll *stack_b);
void	pb(t_dll *stack_b, t_dll *stack_a);
void	ra(t_dll *stack_a);
void	rb(t_dll *stack_b);
void	rr(t_dll *stack_a, t_dll *stack_b);
void	rra(t_dll *stack_a);
void	rrb(t_dll *stack_b);
void	rrr(t_dll *stack_a, t_dll *stack_b);
void	sa(t_dll *stack_a);
void	sb(t_dll *stack_b);
void	ss(t_dll *stack_a, t_dll *stack_b);
void	bubble_sort(t_dll *stack_a);
void	select_sort(t_dll *stack_a, t_dll *stack_b);
#endif
