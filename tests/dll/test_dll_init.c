/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:41:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:35:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

static void	test_init_dll(t_dll *target, t_tests *result)
{
	if (target->head != NULL || target->tail != NULL || target->add == NULL
		|| target->pop == NULL || target->swap == NULL || target->rotate == NULL
		|| target->free == NULL)
		result->result[result->result_len++] = TEST_NG;
	else
		result->result[result->result_len++] = TEST_OK;
}

static void	run(void (*test)(t_dll *t, t_tests *r), t_tests *result)
{
	t_dll	*target;

	target = init_dll();
	test(target, result);
	target->free(&target);
}

void	test_init_dll_run()
{
	t_tests	*result;

	result = test_result_init("test_init_dll");
	if (!result)
		return ;
	run(test_init_dll, result);
	result->show(result);
}