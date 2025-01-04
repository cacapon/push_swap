/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:39 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/04 15:32:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLY_LINKED_LIST_H
# define DOUBLY_LINKED_LIST_H

typedef enum e_dll_sts
{
	DLL_OK,
	DLL_NG,
	DLL_EMPTY,
	DLL_FULL
}						t_dll_sts;

typedef struct e_dll_node
{
	int					value;
	struct e_dll_node	*prev;
	struct e_dll_node	*next;

}						t_dll_node;

typedef struct e_dll
{
	t_dll_node			*head;
	t_dll_node			*tail;

	void				(*add)(int value);
	t_dll_node			(*pop)(void);
	void				(*swap)(void);
	void				(*rotate)(int direction);
	void				(*free)(void);
}						t_dll;

t_dll					*init_dll(void);
void					add_dll(int value);
t_dll_node				pop_dll(void);
void					swap_dll(void);
void					rotate_dll(int direction);
void					free_dll(void);

#endif