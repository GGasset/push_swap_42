/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:37 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/17 16:30:46 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *stacks, int write_instruction)
{
	stacks->a = stacks->a->prev;
	stacks->mov_count += write_instruction != 0;
	write(1, "rra\n", 4 * (write_instruction != 0));

}

void	rrb(t_data *stacks, int write_instruction)
{
	stacks->b = stacks->b->prev;
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
