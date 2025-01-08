/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_methods.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/08 11:22:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doubly_linked_list.h"

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
	int	tmp;

	if (!self || !self->head || !self->head->next)
		return ;
	tmp = self->head->value;
	self->head->value = self->head->next->value;
	self->head->next->value = tmp;
}

void	rotate_dll(t_dll *self, t_dll_direction direction)
{
	if (!self || !self->head || !self->tail)
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
	size_t		count;
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