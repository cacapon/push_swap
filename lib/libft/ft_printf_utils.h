/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:10:23 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/08 11:27:34 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

// includes
# include "ft_printf_define.h"
# include <stdint.h>
# include <unistd.h>

// functions
//// ft_printf_utils1.c

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnum_fd(int n, int fd);
size_t	ft_putunum_fd(unsigned int n, int fd);
size_t	ft_puthex_fd(unsigned int n, int fd, int is_upper);

//// ft_printf_utils2.c

size_t	ft_putptr_fd(void *ptr, int fd);
void	*ftp_memset(void *b, int c, size_t len);

#endif