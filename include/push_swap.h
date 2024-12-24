/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/24 11:52:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"

// enum
typedef enum e_stack_type
{
	STACK_A,
	STACK_B,
	STACK_BOTH,
}		t_stack_type;

typedef enum e_psh_swp_sts
{
	PSH_SWP_OK,
	PSH_SWP_NG,
}		t_psh_swp_sts;

// prototype
void	swap(int *stack, t_stack_type type);
void	push(int *from_stack, int *to_stack, t_stack_type type);
void	rotate(int *stack, t_stack_type type);
void	rv_rotate(int *stack, t_stack_type type);

#endif