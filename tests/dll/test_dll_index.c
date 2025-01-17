/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 15:46:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

static void	test_index_dll(t_dll *target, t_tests *result)
{
	target->append(target, 10);
	target->append(target, 20);
	target->append(target, 30);
	if (target->index(target, 30) == 2)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

static void	test_index_dll_not_found(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->add(target, 20);
	target->add(target, 30);
	if (target->index(target, 50) == -1)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

static void	test_index_dll_empty(t_dll *target, t_tests *result)
{
	if (target->index(target, 0) == -1)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_index_dll_run(void)
{
	t_tests	*result;

	result = test_result_init("test_index_dll");
	if (!result)
		return ;
	test_dll_run(test_index_dll, result);
	test_dll_run(test_index_dll_not_found, result);
	test_dll_run(test_index_dll_empty, result);
	result->show(result);
}
