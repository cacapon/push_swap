/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_in_int.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:45:44 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 21:57:59 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_IS_IN_INT_H
# define TEST_IS_IN_INT_H

# include "test.h"

typedef struct s_test_case
{
	int		v;
	int		ck;
	int		*arr;
	size_t	size;
	char	*mes;
}			t_test_case;

#endif