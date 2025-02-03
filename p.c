/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:57:25 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/29 15:08:06 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *stacks)
{
	int	b_value;
	int	sorted_pos;

	stacks->mov_count++;
	write(1, "pa\n", 3);
	if (!stacks->b->contains_val)
		return ;
	stacks->b_size--;
	stacks->a_size++;
	b_value = stacks->b->val;
	sorted_pos = stacks->b->sorted_i;
	stacks->b->contains_val = FALSE;
	stacks->b = stacks->b->next;
	stacks->a = stacks->a->prev;
	stacks->a->contains_val = TRUE;
	stacks->a->val = b_value;
	stacks->a->sorted_i = sorted_pos;
}

void	pb(t_data *stacks)
{
	int	a_value;
	int	sorted_pos;

	stacks->mov_count++;
	write(1, "pb\n", 3);
	if (!stacks->a->contains_val)
		return ;
	stacks->a_size--;
	stacks->b_size++;
	a_value = stacks->a->val;
	sorted_pos = stacks->a->sorted_i;
	stacks->a->contains_val = FALSE;
	stacks->a = stacks->a->next;
	stacks->b = stacks->b->prev;
	stacks->b->contains_val = TRUE;
	stacks->b->val = a_value;
	stacks->b->sorted_i = sorted_pos;
}
