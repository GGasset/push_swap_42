/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:37 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/17 13:12:17 by ggasset-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	rra(t_data *stacks, int write_instruction)
{
	t_crc_nd	*last_node;
	int			last_value;
	int			sorted_pos;

	if (!stacks->a->contains_val || !stacks->a->next->contains_val)
		return ;
	last_node = get_last_valued(stacks->a);
	last_value = last_node->val;
	sorted_pos = last_node->sorted_i;
	last_node->contains_val = FALSE;
	stacks->a = stacks->a->prev;
	stacks->a->val = last_value;
	stacks->a->sorted_i = sorted_pos;
	stacks->a->contains_val = TRUE;
	stacks->mov_count += write_instruction != 0;
	write(1, "rra\n", 4 * (write_instruction != 0));
}

void	rrb(t_data *stacks, int write_instruction)
{
	t_crc_nd	*last_node;
	int			last_value;
	int			sorted_pos;

	if (!stacks->b->contains_val || !stacks->b->next->contains_val)
		return ;
	last_node = get_last_valued(stacks->b);
	last_value = last_node->val;
	sorted_pos = last_node->sorted_i;
	last_node->contains_val = FALSE;
	stacks->b = stacks->b->prev;
	stacks->b->val = last_value;
	stacks->b->sorted_i = sorted_pos;
	stacks->b->contains_val = TRUE;
	stacks->mov_count += write_instruction != 0;
	write(1, "rrb\n", 4 * (write_instruction != 0));
}

void	rrr(t_data *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	stacks->mov_count++;
	write(1, "rrr\n", 4);
}
