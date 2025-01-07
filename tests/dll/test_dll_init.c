/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:41:15 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 15:39:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

void	test_init_dll(t_dll *target, t_tests *result)
{
	if (target->head != NULL || target->tail != NULL || target->add == NULL
		|| target->pop == NULL || target->swap == NULL || target->rotate == NULL
		|| target->free == NULL)
		result->result[result->result_len++] = TEST_NG;
	else
		result->result[result->result_len++] = TEST_OK;
}
