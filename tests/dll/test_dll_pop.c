/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:24:50 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 15:44:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

void	test_pop_dll_normal(t_dll *target, t_tests *result)
{
	t_dll_node	*get_node;

	target->add(target, 10);
	target->add(target, 20);
	target->add(target, 30);
	get_node = target->pop(target);
	if (get_node->value != 10)
		result->result[result->result_len++] = TEST_NG;
	else
		result->result[result->result_len++] = TEST_OK;
}

void	test_pop_dll_empty(t_dll *target, t_tests *result)
{
	t_dll_node	*get_node;

	get_node = target->pop(target);
	if (get_node != NULL)
		result->result[result->result_len++] = TEST_NG;
	else
		result->result[result->result_len++] = TEST_OK;
}