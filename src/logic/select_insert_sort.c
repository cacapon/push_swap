/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:46 by ttsubo            #+#    #+#             */
/*   Updated: 2026/11/23 06:47:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_back_a(t_dll *a, t_dll *b) {
  int a_left;
  int a_right;

  while (b->head) {
    a_left = get_a_left_mv(b->head->value, a);
    a_right = (a->size - a_left) % a->size;
    if (a_left < a_right)
      while (a_left--)
        ra(a);
    else
      while (a_right--)
        rra(a);
    pa(a, b);
  }
}

static void calculate_and_execute(t_dll *stack_a, t_dll *stack_b) {
  size_t ite;
  t_cmd_mv current;
  t_cmd_mv min_mv;

  min_mv = get_cmd_mv(0, stack_a, stack_b);
  ite = 1;
  while (ite < stack_a->size) {
    current = get_cmd_mv(ite, stack_a, stack_b);
    if (current.total < min_mv.total)
      min_mv = current;
    ite++;
  }
  rotate_and_push_b(&stack_a, &stack_b, min_mv);
}

/*
        aがなくなるまで
                xをプッシュするために必要なa,bの移動量を求める
   (a<,a>,b<,b>)...[0]
                [0]からコマンド用の移動量を計算...[1]:[(a<>,b<>,common<>,mv)...]
                [1]の一番小さいものを選択...[2]:(a<>,b<>,common<>,mv)
                [2]に従ってコマンドを実行する
                bにプッシュ
        bの最大値を先頭に合わせる
        aにプッシュ
*/
void select_insert_sort(t_dll *stack_a, t_dll *stack_b) {
  while (stack_a->size > 5)
    calculate_and_execute(stack_a, stack_b);
  short_logic(stack_a, stack_b);
  move_max_to_head_b(&stack_b);
  push_back_a(stack_a, stack_b);
  move_min_to_head_a(&stack_a);
}
