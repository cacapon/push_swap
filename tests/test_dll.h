/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dll.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:30:56 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/07 15:44:45 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_DLL_H
# define TEST_DLL_H

# include "doubly_linked_list.h"
# define TEST_NAME "doubly_linked_list"
# define TEST_OK	'.'
# define TEST_NG	'F'

typedef struct e_tests
{
	char	name[32];
	char	result[256];
	size_t	result_len;
}			t_tests;

t_dll	*test_dll_pre(void);
void	test_dll_post(t_dll *target);

void	test_init_dll(t_dll *target, t_tests *result);
void	test_add_dll_one(t_dll *target, t_tests *result);
void	test_add_dll_multi(t_dll *target, t_tests *result);
void	test_pop_dll_normal(t_dll *target, t_tests *result);
void	test_pop_dll_empty(t_dll *target, t_tests *result);

#endif
