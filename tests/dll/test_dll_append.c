/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/26 16:21:56 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

static void	test_append_dll_one(t_dll *target, t_tests *result)
{
	target->append(target, 10);
	if (target->head == target->tail)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

// ...-[10]-[20]-[30]-...
static void	test_append_dll_multi(t_dll *target, t_tests *result)
{
	target->append(target, 10);
	target->append(target, 20);
	target->append(target, 30);
	if (target->head->value == 10 && target->tail->value == 30)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_append_dll_run(void)
{
	t_tests	*result;

	result = test_result_init("test_append_dll");
	if (!result)
		return ;
	test_dll_run(test_append_dll_one, result);
	test_dll_run(test_append_dll_multi, result);
	result->show(result);
}
