/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:47:52 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 18:54:23 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_with_error(const char *str, int *error)
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
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		return (*error = 1, 0);
	return ((int)(sign * num));
}

static char	**free_tokens(char **tokens, size_t index)
{
	while (index > 0)
		free(tokens[--index]);
	free(tokens);
	return (NULL);
}

/**
 * @brief
 *
 * @param arg
 * @return int
 */
static t_psh_swp_sts	validate_input(char *input)
{
	char	**tokens;
	int		error;
	int		i;

	tokens = ft_split(input, ' ');
	if (!tokens)
		return (PSH_SWP_NG);
	i = 0;
	while (tokens[i] != NULL)
	{
		error = 0;
		ft_atoi_with_error(tokens[i], &error);
		if (error)
			return (free_tokens(tokens, i), PSH_SWP_NG);
		i++;
	}
	free_tokens(tokens, i);
	return (PSH_SWP_OK);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (validate_input(argv[1]) == 0)
		ft_printf("OK");
	else
		ft_printf("NG");
	return (0);
}
