/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:38:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:42:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_dll.h"

void	test_dll_run(void (*test)(t_dll *t, t_tests *r), t_tests *result)
{
	t_dll	*target;

	target = init_dll();
	test(target, result);
	target->free(&target);
}

int	main(void)
{
	test_init_dll_run();
	test_add_dll_run();
	test_pop_dll_run();
	// run(test_init_dll, result);
	// run(test_add_dll_one, result);
	// run(test_add_dll_multi, result);
	// run(test_pop_dll_normal, result);
	// run(test_pop_dll_empty, result);
	// run(test_swap, result);
	// run(test_swap_one, result);
	// run(test_swap_empty, result);
	// run(test_rotate_up, result);
	// run(test_rotate_down, result);
	// run(test_rotate_one, result);
	// run(test_rotate_empty, result);
}
