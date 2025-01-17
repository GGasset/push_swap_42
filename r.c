/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:19:31 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/17 13:11:40 by ggasset-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

void	ra(t_data *stacks, int write_instruction)
{
	t_crc_nd	*last_valued;
	int			a_val;
	int			sort_pos;

	if (!stacks->a->contains_val || !stacks->a->next->contains_val)
		return ;
	a_val = stacks->a->val;
	sort_pos = stacks->a->sorted_i;
	stacks->a->contains_val = FALSE;
	stacks->a = stacks->a->next;
	last_valued = get_last_valued(stacks->a)->next;
	last_valued->val = a_val;
	last_valued->sorted_i = sort_pos;
	last_valued->contains_val = TRUE;
	stacks->mov_count += write_instruction != 0;
	write(1, "ra\n", 3 * (write_instruction != 0));
}

void	rb(t_data *stacks, int write_instruction)
{
	t_crc_nd	*last_valued;
	int			b_val;
	int			sort_pos;

	if (!stacks->b->contains_val || !stacks->b->next->contains_val)
		return ;
	b_val = stacks->b->val;
	sort_pos = stacks->b->sorted_i;
	stacks->b->contains_val = FALSE;
	stacks->b = stacks->b->next;
	last_valued = get_last_valued(stacks->b)->next;
	last_valued->contains_val = TRUE;
	last_valued->sorted_i = sort_pos;
	last_valued->val = b_val;
	stacks->mov_count += write_instruction != 0;
	write(1, "rb\n", 3 * (write_instruction != 0));
}

void	rr(t_data *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	stacks->mov_count++;
	write(1, "rr\n", 3);
}
