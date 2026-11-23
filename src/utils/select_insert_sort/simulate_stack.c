/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 07:46:00 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 08:07:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	*clone_stack(t_dll *src)
{
	t_dll	*dst;
	size_t	i;

	dst = init_dll();
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->size)
	{
		dst->append(dst, src->get(src, i));
		i++;
	}
	return (dst);
}

void	simulate_rotate(t_dll *a, t_dll *b, t_cmd_mv cmd)
{
	while (cmd.c < 0)
	{
		cmd.c++;
		a->rotate(a, DLL_SHIFT_UP);
		b->rotate(b, DLL_SHIFT_UP);
	}
	while (cmd.c > 0)
	{
		cmd.c--;
		a->rotate(a, DLL_SHIFT_DOWN);
		b->rotate(b, DLL_SHIFT_DOWN);
	}
	while (cmd.a < 0 && (cmd.a++, 1))
		a->rotate(a, DLL_SHIFT_UP);
	while (cmd.a > 0 && (cmd.a--, 1))
		a->rotate(a, DLL_SHIFT_DOWN);
	while (cmd.b < 0 && (cmd.b++, 1))
		b->rotate(b, DLL_SHIFT_UP);
	while (cmd.b > 0 && (cmd.b--, 1))
		b->rotate(b, DLL_SHIFT_DOWN);
}

void	simulate_pb(t_dll *a, t_dll *b)
{
	t_dll_node	*node;

	node = a->pop(a);
	if (node == NULL)
		return ;
	b->add(b, node->value);
	free(node);
}
