/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 17:24:46 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

// 30-20-10 -> 20-10-30 
void	test_rotate_up(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->add(target, 20);
	target->add(target, 30);
	target->rotate(target, DLL_SHIFT_UP);
	if (target->head->value == 20 && target->tail->value == 30)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

// 30-20-10 -> 10-30-20
void	test_rotate_down(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->add(target, 20);
	target->add(target, 30);
	target->rotate(target, DLL_SHIFT_DOWN);
	if (target->head->value == 10 && target->tail->value == 20)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_rotate_one(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->rotate(target, DLL_SHIFT_DOWN);
	if (target->head->value == 10 && target->tail->value == 10)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

void	test_rotate_empty(t_dll *target, t_tests *result)
{
	target->rotate(target, DLL_SHIFT_UP);
	if (!target->head && !target->tail)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}
