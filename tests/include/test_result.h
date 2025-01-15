/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:09:42 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:42:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RESULT_T
# define TEST_RESULT_T
# define TEST_OK '.'
# define TEST_NG 'F'

# include "../../lib/libft/libft.h"
# include "stddef.h"

typedef struct e_tests	t_tests;

typedef struct e_tests
{
	char				name[32];
	char				result[256];
	size_t				result_len;


	void				(*show)(t_tests *self);
	void				(*set_name)(t_tests *self, char *name);
}						t_tests;

// methods
void					test_result_show(t_tests *result);
void					test_result_setname(t_tests *result, char *name);

// prototype
t_tests	*test_result_init(char *name);

#endif