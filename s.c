/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:51:18 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/17 15:41:55 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *stacks, int write_instruction)
{
	t_crc_nd	*start;
	t_crc_nd	*tmp0;
	t_crc_nd	*tmp1;
	int			tmp;

	stacks->mov_count += 1 * (write_instruction != 0);
	write(1, "sa\n", 3 * (write_instruction != 0));
	start = stacks->a;
	tmp0 = get_next_valued(start, start, 1);
	if (!tmp0)
		return ;
	tmp1 = get_next_valued(start, tmp0->next, 0);
	if (!tmp1)
		return ;
	tmp = tmp1->val;
	tmp1->val = tmp0->val;
	tmp0->val = tmp;
}

void	sb(t_data *stacks, int write_instruction)
{
	t_crc_nd	*start;
	t_crc_nd	*tmp0;
	t_crc_nd	*tmp1;
	int			tmp;

	stacks->mov_count += 1 * (write_instruction != 0);
	write(1, "sb\n", 3 * (write_instruction != 0));
	start = stacks->b;
	tmp0 = get_next_valued(start, start, 1);
	if (!tmp0)
		return ;
	tmp1 = get_next_valued(start, tmp0->next, 0);
	if (!tmp1)
		return ;
	tmp = tmp1->val;
	tmp1->val = tmp0->val;
	tmp0->val = tmp;
}

void	ss(t_data *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	stacks->mov_count += 1;
	write(1, "ss\n", 3);
}
