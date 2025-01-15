/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:30:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:48:02 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DLL_H
# define TEST_DLL_H

# include "doubly_linked_list.h"
# include "test_result.h"
# define TEST_NAME "doubly_linked_list"

t_dll	*test_dll_pre(void);
void	test_dll_post(t_dll *target);

void	test_dll_run(void (*test)(t_dll *t, t_tests *r), t_tests *result);
void	test_init_dll_run();
void	test_add_dll_run();
void	test_pop_dll_run();
void	test_swap_dll_run();
void	test_rotate_dll_run();

#endif
