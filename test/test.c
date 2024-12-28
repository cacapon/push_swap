/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:51:58 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 21:57:53 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_result_output(char *test_name, t_test_result result)
{
	ft_printf("%s\t", test_name);
	ft_printf("OK:%d\tNG:%d\t", result.ok, result.ng);
	ft_printf("mes:%s\n", result.mes);
}

int	main(void)
{
	t_test_result	result;

	result = (t_test_result){.ok = 0, .ng = 0};
	test_is_in_int(&result);
	test_result_output("test_is_in_int", result);
}
