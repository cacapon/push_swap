/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 20:56:14 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "doubly_linked_list.h"

// enum

typedef enum e_push_swap_err
{
	PSW_OK,
	ERR_PSW_OUTOFRANGE,
	ERR_PSW_NOT_NUM,
}			t_push_swap_err;

// struct

typedef struct e_move_count
{
	size_t	left;
	size_t	right;
}			t_move_count;

typedef struct e_move_cmd
{
	size_t	a_r;
	size_t	a_l;
	size_t	b_r;
	size_t	b_l;
}			t_move_cmd;

typedef struct e_cmd_mv
{
	int		a;
	int		b;
	int		c;
	int		total;
}			t_cmd_mv;

// ft_utils

int			ft_abs(int a);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_atoi_with_error(const char *str, t_push_swap_err *error);

// select_insert_sort_utils

void		exec_cmd(t_dll **a, t_dll **b, t_cmd_mv cmd);
int			get_b_left_mv(int value, t_dll *b);
t_cmd_mv	get_cmd_mv(size_t ite, t_dll *a, t_dll *b);
t_cmd_mv	get_min_mv(t_cmd_mv *cmd_moves, size_t size);
void		move_max_to_head(t_dll **b);

// prototype

void		pa(t_dll *stack_a, t_dll *stack_b);
void		pb(t_dll *stack_b, t_dll *stack_a);
void		ra(t_dll *stack_a);
void		rb(t_dll *stack_b);
void		rr(t_dll *stack_a, t_dll *stack_b);
void		rra(t_dll *stack_a);
void		rrb(t_dll *stack_b);
void		rrr(t_dll *stack_a, t_dll *stack_b);
void		sa(t_dll *stack_a);
void		sb(t_dll *stack_b);
void		ss(t_dll *stack_a, t_dll *stack_b);
void		bubble_sort(t_dll *stack_a);
void		select_sort(t_dll *stack_a, t_dll *stack_b);
void		select_insert_sort(t_dll *stack_a, t_dll *stack_b);

#endif
