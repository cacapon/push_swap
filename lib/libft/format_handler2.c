/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:24:10 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/23 20:06:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_handler.h"

int	handle_ptr(va_list args)
{
	return (ptf_putptr_fd(va_arg(args, void *), FD_STDOUT));
}

int	handle_lower_hex(va_list args)
{
	return (ptf_puthex_fd(va_arg(args, unsigned int), FD_STDOUT, HEX_IS_LOWER));
}

int	handle_upper_hex(va_list args)
{
	return (ptf_puthex_fd(va_arg(args, unsigned int), FD_STDOUT, HEX_IS_UPPER));
}
