/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 14:33:54 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"


void	test_add_dll_one(t_test_result *result)
{
	t_dll	*target;

	target = test_dll_pre();
	target->add(target, 10);
	if (target->head->value != 10 || target->tail->value != 10)
		result->result[result->result_len++] = TEST_NG;
	else
		result->result[result->result_len++] = TEST_OK;
	test_dll_post(target);
}


void	test_add_dll_multi(t_test_result *result)
{
	t_dll	*target;

	target = test_dll_pre();
	target->add(target, 10);
	target->add(target, 20);
	if (target->head->value != 10 || target->tail->value != 20)
		result->result[result->result_len++] = TEST_NG;
	test_dll_post(target);
}