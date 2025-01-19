/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2025/01/19 20:37:01 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief cmdの移動量の分スタックのコマンドを実行し、最後にbにプッシュします。
 * 
 * @param a 
 * @param b 
 * @param cmd 
 * @note	cmdの中にあるa,b,cは整数です
 * @note	負の数の場合は数値分シフトアップ
 * @note	正の数の場合は数値分シフトダウンします。
 */
void	exec_cmd(t_dll **a, t_dll **b, t_cmd_mv cmd)
{
	while (cmd.a != 0 || cmd.b != 0 || cmd.c != 0)
	{
		if (cmd.c < 0 && cmd.c++)
			rr(*a, *b);
		else if (cmd.c > 0 && cmd.c--)
			rrr(*a, *b);
		else if (cmd.a < 0 && cmd.a++)
			ra(*a);
		else if (cmd.a > 0 && cmd.a--)
			rra(*a);
		else if (cmd.b < 0 && cmd.b++)
			rb(*b);
		else if (cmd.b > 0 && cmd.b--)
			rrb(*b);
	}
	pb(*b, *a);
}
