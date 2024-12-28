/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:40:58 by ttsubo            #+#    #+#             */
/*   Updated: 2024/12/28 18:16:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_utils.h"

/**
 * @brief vがarrに含まれているかを判定します
 *
 * @param v		: 含まれているか確認する値
 * @param arr	: 対象の配列
 * @param size	: 配列のサイズ
 * @retval 1	: 含まれている
 * @retval 0	: 含まれていない
 */
int	is_in_int(int v, int *arr, size_t size)
{
	unsigned int	i;

	if (!arr)
		return (0);
	i = 0;
	while (i < size)
		if (v == arr[i++])
			return (1);
	return (0);
}
