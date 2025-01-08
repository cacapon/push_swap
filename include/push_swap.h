/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/08 13:53:49 by ttsubo           ###   ########.fr       */
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
void	swap(int *stack, t_stack_type type);
void	push(int *from_stack, int *to_stack, t_stack_type type);
void	rotate(int *stack, t_stack_type type);
void	rv_rotate(int *stack, t_stack_type type);

#endif
