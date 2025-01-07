/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:20:59 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 15:39:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "test_dll.h"

// t_dll	*test_dll_pre(void)
// {
// 	return (init_dll());
// }

// void	test_dll_post(t_dll *target)
// {
// 	target->free(target);
// }

// void	test_pop_dll(t_tests *result)
// {
// 	t_dll	*target;

// 	target = test_dll_pre();
// 	test_dll_post(target);
// }
// void	test_swap_dll(t_tests *result)
// {
// 	t_dll	*target;

// 	target = test_dll_pre();
// 	test_dll_post(target);
// }
// void	test_rotate_dll(t_tests *result)
// {
// 	t_dll	*target;

// 	target = test_dll_pre();
// 	test_dll_post(target);
// }
// void	test_free_dll(t_tests *result)
// {
// 	t_dll	*target;

// 	target = test_dll_pre();
// 	test_dll_post(target);
// }

// void	test_dll_run(void (*test)(t_dll *tgt, t_tests *result), t_tests *result)
// {
// 	t_dll	*target;

// 	target = test_dll_pre();
// 	test(target, result);
// 	test_dll_post(target);
// }

// t_tests	*test_dll(t_tests *result)
// {
// 	int i;
// 	t_tests *result;

// 	i = 0;
// 	*result = (t_tests){.result_len = 0};
// 	while (TEST_NAME[i])
// 		result->name[i] = TEST_NAME[i++];
// 	test_dll_run(test_init_dll, result);
// 	test_dll_run(test_add_dll_one, result);
// 	test_dll_run(test_add_dll_multi, result);
// 	return (result);
// }