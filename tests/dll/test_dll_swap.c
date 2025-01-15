/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:45:10 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

// 30-20-10 -> 20-30-10
void	test_swap(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->add(target, 20);
	target->add(target, 30);
	target->swap(target);
	if (target->head->value == 20 && target->head->next->value == 30)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_swap_one(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->swap(target);
	if (target->head->value == 10)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_swap_empty(t_dll *target, t_tests *result)
{
	target->swap(target);
	if (!target->head && !target->tail)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_swap_dll_run()
{
	t_tests	*result;

	result = test_result_init("test_swap_dll");
	if (!result)
		return ;
	test_dll_run(test_swap, result);
	test_dll_run(test_swap_one, result);
	test_dll_run(test_swap_empty, result);
	result->show(result);
}