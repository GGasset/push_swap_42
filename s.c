/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:51:18 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/17 12:48:31 by ggasset-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	sa(t_data *stacks, int write_instruction)
{
	int	tmp;
	int	sorted_pos;

	stacks->mov_count += 1 * (write_instruction != 0);
	write(1, "sa\n", 3 * (write_instruction != 0));
	if (!stacks->a->contains_val || !stacks->a->next->contains_val)
		return ;
	tmp = stacks->a->val;
	sorted_pos = stacks->a->sorted_i;
	stacks->a->val = stacks->a->next->val;
	stacks->a->sorted_i = stacks->a->next->sorted_i;
	stacks->a->next->val = tmp;
	stacks->a->next->sorted_i = sorted_pos;
}

void	sb(t_data *stacks, int write_instruction)
{
	int	tmp;
	int	sorted_pos;

	stacks->mov_count += 1 * (write_instruction != 0);
	write(1, "sb\n", 3 * (write_instruction != 0));
	if (!stacks->b->contains_val || !stacks->b->next->contains_val)
		return ;
	tmp = stacks->b->val;
	sorted_pos = stacks->b->sorted_i;
	stacks->b->sorted_i = stacks->b->next->sorted_i;
	stacks->b->val = stacks->b->next->val;
	stacks->b->next->val = tmp;
	stacks->b->next->sorted_i = sorted_pos;
}

void	ss(t_data *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	stacks->mov_count += 1;
	write(1, "ss\n", 3);
}
