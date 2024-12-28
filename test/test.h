/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:52:14 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 21:58:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../lib/libft/libft.h"
# include "push_swap_utils.h"

typedef enum e_psh_swp_test
{
	PSH_SWP_TEST_OK,
	PSH_SWP_TEST_NG,
}			t_psh_swp_test;

typedef struct e_test_result
{
	int		ok;
	int		ng;
	char	mes[1024];
}			t_test_result;

void		test_result_output(char *test_name, t_test_result result);
void		test_is_in_int(t_test_result *result);

#endif