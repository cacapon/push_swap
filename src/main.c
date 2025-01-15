/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:47:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 17:42:58 by ttsubo           ###   ########.fr       */
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
		if (error != PSW_OK || (*stack)->is_in((*stack), value))
			return (error);
		(*stack)->add((*stack), value);
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
		return (ft_printf("Error\n"), 1);
	stack_a = _init_stack();
	stack_b = _init_stack();
	if (_setup_stack_a(argc, argv, &stack_a) != PSW_OK)
		return (_free_stacks(&stack_a, &stack_b), ft_printf("Error\n"), 1);
	bubble_sort(stack_a);
	return (_free_stacks(&stack_a, &stack_b), 0);
}
