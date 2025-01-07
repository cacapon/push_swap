/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 16:37:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

// TODO 後でいどうさせる
t_dll	*init_dll(void)
{
	t_dll	*dll;

	dll = (t_dll *)ft_calloc(sizeof(t_dll), 1);
	if (!dll)
		return (NULL);
	dll->head = NULL;
	dll->tail = NULL;
	dll->size = 0;
	dll->add = add_dll;
	dll->pop = pop_dll;
	dll->swap = swap_dll;
	dll->rotate = rotate_dll;
	dll->free = free_dll;
	return (dll);
}

void	add_dll(t_dll *self, int value)
{
	t_dll_node	*node;

	node = (t_dll_node *)ft_calloc(sizeof(t_dll_node), 1);
	node->value = value;
	if (!self->head)
	{
		self->head = node;
		self->tail = node;
	}
	self->head->prev = node;
	node->next = self->head;
	self->tail->next = node;
	node->prev = self->tail;
	self->tail = node;
	self->size++;
}

t_dll_node	*pop_dll(t_dll *self)
{
	t_dll_node	*node;

	if (!self->head)
		return (NULL);
	node = self->head;
	self->head = self->head->next;
	self->head->prev = self->tail;
	node->prev = node;
	node->next = node;
	self->size--;
	return (node);
}

void	swap_dll(t_dll *self)
{
	t_dll_node	*tmp_node;

	if (!self || !self->head || !self->head->next)
		return ;
	tmp_node = self->head;
	self->head = self->head->next;
	self->head->next = tmp_node;
}

void	rotate_dll(t_dll *self, t_dll_direction direction)
{
	if (!self)
		return ;
	if (direction == DLL_SHIFT_UP)
	{
		self->head = self->head->next;
		self->tail = self->tail->next;
	}
	else if (direction == DLL_SHIFT_DOWN)
	{
		self->head = self->head->prev;
		self->tail = self->tail->prev;
	}
}

void	free_dll(t_dll **self)
{
	size_t 		count;
	t_dll_node	*node;
	t_dll_node	*next;

	if (!self || !(*self))
		return ;
	node = (*self)->head;
	count = 0;
	while (count < (*self)->size)
	{
		next = node->next;
		free(node);
		node = next;
		count++;
	}
	free(*self);
	*self = NULL;
}
