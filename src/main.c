/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:47:52 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/08 13:54:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dll			*stack_a;
	t_dll			*stack_b;
	int				i;
	int				value;
	t_push_swap_err	error;

	if (argc <= 1)
		return (ft_printf("Error\n"), 1);
	stack_a = ft_calloc(sizeof(t_dll), 1);
	stack_b = ft_calloc(sizeof(t_dll), 1);
	stack_a = init_dll();
	stack_b = init_dll();
	i = 1;
	error = PSW_OK;
	while (i < argc)
	{
		value = ft_atoi_with_error(argv[i++], &error);
		if (error != PSW_OK || stack_a->is_in(stack_a, value))
			return (ft_printf("Error\n"), 1);
		stack_a->add(stack_a, value);
	}
	stack_a->free(&stack_a);
	stack_b->free(&stack_b);
	return (0);
}
