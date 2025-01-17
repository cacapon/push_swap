/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:47:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/20 12:19:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_dll	*_init_stack(void)
{
	t_dll	*stack;

	stack = init_dll();
	return (stack);
}

static t_push_swap_err	_setup_stack_a(int argc, char **argv, t_dll **stack)
{
	int				i;
	int				value;
	t_push_swap_err	error;

	i = 1;
	error = PSW_OK;
	while (i < argc)
	{
		value = ft_atoi_with_error(argv[i++], &error);
		if (error != PSW_OK)
			return (error);
		if ((*stack)->is_in((*stack), value))
			return (ERR_PSW_DUPLICATE_NUM);
		(*stack)->append((*stack), value);
	}
	return (PSW_OK);
}

static t_push_swap_err	_is_sorted(t_dll *a)
{
	t_dll_node	*node;

	if (a->size <= 1)
		return (PSW_OK);
	node = a->head;
	while (node)
	{
		if (node->value >= node->next->value)
			return (ERR_PSW_NOT_SORTED);
		node = node->next;
		if (node->next == a->head)
			break ;
	}
	return (PSW_OK);
}

static void	_free_stacks(t_dll **stack_a, t_dll **stack_b)
{
	(*stack_a)->free(stack_a);
	(*stack_b)->free(stack_b);
}

int	main(int argc, char **argv)
{
	t_dll	*stack_a;
	t_dll	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = _init_stack();
	stack_b = _init_stack();
	if (_setup_stack_a(argc, argv, &stack_a) != PSW_OK)
		return (_free_stacks(&stack_a, &stack_b), ft_printf("Error\n"), 1);
	if (_is_sorted(stack_a) == PSW_OK)
		return (0);
	if (stack_a->size <= 5)
		short_logic(stack_a, stack_b);
	else
		select_insert_sort(stack_a, stack_b);
	return (_free_stacks(&stack_a, &stack_b), 0);
}
