/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:19:28 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/13 18:35:50 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_data *stacks)
{
	t_move	move;

	move_constructor(&move, stacks);
	move.a_pos = get_cheapest(stacks, &move.b_pos);
	while (move.a_pos || move.b_pos)
	{
		get_move(&move);
		real_move(stacks, &move);
	}
	pb(stacks);
}

void	move_to_a(t_data *stacks)
{
	t_move	stacks_data;
	size_t	sorted_position;
	size_t	rotation_count;
	int		is_reverse;

	move_constructor(&stacks_data, stacks);
	sorted_position = get_sorted_position(stacks->a, stacks->b->val);
	rotation_count = get_r_count(sorted_position, stacks_data, &is_reverse);
	while (rotation_count && sorted_position)
	{
		if (is_reverse)
			rra(stacks, TRUE);
		else
			ra(stacks, TRUE);
		rotation_count--;
	}
	pa(stacks);
}

void	rotate_a_to_finish(t_data *stacks)
{
	size_t	min_value_i;
	int		before_median;

	min_value_i = get_min_i(stacks->a);
	before_median = min_value_i <= stacks->a_size / 2;
	while (min_value_i && before_median)
	{
		ra(stacks, TRUE);
		min_value_i--;
	}
	while (min_value_i < stacks->a_size && !before_median)
	{
		rra(stacks, TRUE);
		min_value_i++;
	}
}

// TODO handle small inputs (2 or 3 inputs)
// TODO check if sorted at beginning
void	mech_turkish(t_data *stacks)
{
	if (is_sorted(stacks->a, TRUE, FALSE))
		return ;
	if (stacks->a_size > 3)
	{
		pb(stacks);
		if (stacks->a_size > 3)
			pb(stacks);
	}
	while (stacks->a_size > 3)
	{
		move_cheapest(stacks);
		//print_list(stacks->b);
		//ft_putstr_fd(" b \n", 1);
	}
	ft_putendl_fd("cheapest_end\n", 1);
	if (stacks->a_size == 3)
		sort_three(stacks);
	ft_putendl_fd("three sorted\n", 1);
	//print_list(stacks->a);
	//ft_putstr_fd("\n", 1);
	while (stacks->b_size)
	{
		move_to_a(stacks);
		//print_list(stacks->a);
		//ft_putstr_fd("\n", 1);
	}
	ft_putendl_fd("a_move\n", 1);
	rotate_a_to_finish(stacks);
	ft_putendl_fd("rotate_a\n", 1);
}
