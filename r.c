/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:19:31 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/17 16:27:44 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *stacks, int write_instruction)
{
	stacks->a = stacks->a->next;
	stacks->mov_count += write_instruction != 0;
	write(1, "ra\n", 3 * (write_instruction != 0));
}

void	rb(t_data *stacks, int write_instruction)
{
	stacks->b = stacks->b->next;
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
