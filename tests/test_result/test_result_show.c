/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:11:07 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:53:22 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_result.h"

void	test_result_show(t_tests *result)
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
