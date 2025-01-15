/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:16:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:22:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_result.h"

t_tests	*test_result_init(char *name)
{
	t_tests	*result;

	result = ft_calloc(sizeof(t_tests), 1);
	if (!result)
		return (NULL);
	result->result_len = 0;
	result->set_name = test_result_setname;
	result->show = test_result_show;
	result->set_name(result, name);
	return (result);
}