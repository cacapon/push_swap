/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_in_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:51:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 21:59:28 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_is_in_int.h"

static void	update_result(t_test_result *result, int test_result, char *mes)
{
	if (test_result)
	{
		result->ok++;
	}
	else
	{
		result->ng++;
		ft_strlcpy(result->mes, mes, 1024);
	}
}

void	test_is_in_int(t_test_result *result)
{
	static int	arr[3] = {1, 2, 3};
	t_test_case	t[3];
	size_t		i;
	size_t		len;
	int			rt_val;

	t[0] = (t_test_case){1, 1, arr, 3, "NG: 1 in [1,2,3]"};
	t[1] = (t_test_case){100, 0, arr, 3, "NG: 100 in [1,2,3]"};
	t[2] = (t_test_case){1, 0, NULL, 3, "NG: 1 in NULL"};
	i = 0;
	len = sizeof(t) / sizeof(t[0]);
	while (i < len)
	{
		rt_val = (t[i].ck == is_in_int(t[i].v, t[i].arr, t[i].size));
		update_result(result, rt_val, t[i].mes);
		i++;
	}
}
