/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:38:19 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/17 15:38:19 by ttsubo           ###   ########.fr       */
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
	test_swap_dll_run();
	test_rotate_dll_run();
	test_len_dll_run();
	test_min_dll_run();
}
