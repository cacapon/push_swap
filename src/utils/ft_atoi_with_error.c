/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:41:01 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/24 15:23:42 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 
 * 
 * @param str 
 * @param error 
 * @return int
 * @retval 
 */
int	ft_atoi_with_error(const char *str, t_push_swap_err *error)
{
	long int	sign;
	long int	num;

	sign = 1;
	num = 0;
	*error = 0;
	while (*str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (*error = ERR_PSW_NOT_NUM, 0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (*error = ERR_PSW_NOT_NUM, 0);
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (*error = ERR_PSW_OUTOFRANGE, 0);
		str++;
	}
	return ((int)(sign * num));
}
