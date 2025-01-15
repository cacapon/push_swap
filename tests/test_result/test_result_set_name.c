/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_result_set_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:12:23 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/15 20:15:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_result.h"

void	test_result_setname(t_tests *result, char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		result->name[i] = name[i];
		i++;
	}
}
