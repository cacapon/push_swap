/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:38:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 15:38:54 by ttsubo           ###   ########.fr       */
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

int	main(void)
{
	t_dll	*target;
	t_tests	*result;

	target = init_dll();
	result = ft_calloc(sizeof(t_tests), 1);
	*result = (t_tests){.result_len = 0};
	_set_name(result, "test_dll");
	test_init_dll(target, result);
	test_add_dll_one(target, result);
	test_add_dll_multi(target, result);
	show(result);
}
