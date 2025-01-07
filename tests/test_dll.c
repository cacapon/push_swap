/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:38:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 16:43:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

static void	_set_name(t_tests *result, char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		result->name[i] = name[i];
		i++;
	}
}

static void	show(t_tests *result)
{
	int	i;

	i = 0;
	ft_printf("%s:\t", result->name);
	while (result->result[i])
	{
		if (result->result[i] == TEST_OK)
			ft_printf("\033[32m%c\033[0m", result->result[i]);
		else
			ft_printf("\033[31m%c\033[0m", result->result[i]);
		i++;
	}
	ft_printf("\n");
}

static void	run(void (*test)(t_dll *t, t_tests *r), t_tests *result)
{
	t_dll	*target;

	target = init_dll();
	test(target, result);
	target->free(&target);
}

int	main(void)
{
	t_tests	*result;

	result = ft_calloc(sizeof(t_tests), 1);
	*result = (t_tests){.result_len = 0};
	_set_name(result, "test_dll");
	run(test_init_dll, result);
	run(test_add_dll_one, result);
	run(test_add_dll_multi, result);
	run(test_pop_dll_normal, result);
	run(test_pop_dll_empty, result);
	show(result);
}
