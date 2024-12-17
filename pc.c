/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:57:25 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/17 17:36:54 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *stack)
{
	t_crc_nd	*b_value;
	t_crc_nd	*stack_a;
	t_crc_nd	*push_pos;

	stack->mov_count++;
	write(1, "pa\n", 3);
	b_value = get_next_valued(stack->b, stack->b, TRUE);
	if (!b_value)
		return ;
	stack_a = stack->a;
	push_pos = get_next_valued(stack_a, stack_a, TRUE);
	if (push_pos == stack_a)
		rra(stack, 0);
	push_pos = push_pos->prev;
	push_pos->contains_val = TRUE;
	push_pos->val = b_value->val;
	b_value->contains_val = FALSE;
}

void	pb(t_data *stacks)
{
	
}
