/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 16:30:13 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

void	test_add_dll_one(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	if (target->head == target->tail)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}

// ...-[10]-[20]-[30]-...
void	test_add_dll_multi(t_dll *target, t_tests *result)
{
	target->add(target, 10);
	target->add(target, 20);
	target->add(target, 30);
	if (target->head->next == target->tail->prev)
		result->result[result->result_len++] = TEST_OK;
	else
		result->result[result->result_len++] = TEST_NG;
}
