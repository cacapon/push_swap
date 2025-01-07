/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 15:07:47 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

# include "../lib/libft/libft.h"

typedef struct e_dll_node	t_dll_node;
typedef struct e_dll		t_dll;

typedef enum e_dll_sts
{
	DLL_OK,
	DLL_NG,
	DLL_EMPTY,
	DLL_FULL
}							t_dll_sts;

typedef enum e_dll_direction
{
	DLL_SHIFT_UP,
	DLL_SHIFT_DOWN
}							t_dll_direction;

typedef struct e_dll_node
{
	int						value;
	t_dll_node				*prev;
	t_dll_node				*next;

}							t_dll_node;

typedef struct e_dll
{
	t_dll_node				*head;
	t_dll_node				*tail;

	void					(*add)(t_dll *self, int value);
	t_dll_node				*(*pop)(t_dll *self);
	void					(*swap)(t_dll *self);
	void					(*rotate)(t_dll *self, t_dll_direction direction);
	void					(*free)(t_dll *self);
}							t_dll;

t_dll						*init_dll(void);
void						add_dll(t_dll *self, int value);
t_dll_node					*pop_dll(t_dll *self);
void						swap_dll(t_dll *self);
void						rotate_dll(t_dll *self, t_dll_direction direction);
void						free_dll(t_dll *self);

#endif