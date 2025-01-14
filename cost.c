/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:59:40 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/13 16:58:59 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	theoretic_move(t_move *move)
{
	move->a_pos += move->a_move;
	if (move->a_pos)
		move->a_pos = move->a_len % move->a_pos;
	move->b_pos += move->b_move;
	if (move->b_pos)
		move->b_pos = move->b_len % move->b_pos;
}

void	get_move(t_move *move)
{
	move->a_move = 1 - 2 * (move->a_pos <= move->median_a);
	move->a_move *= move->a_pos != 0;
	move->b_move = 1 - 2 * (move->b_pos <= move->median_b);
	move->b_move *= move->b_pos != 0;
}

/*
	Before is <=, After >
	## All cases to get nbrs to top of stack
---
		- both before median
			* rr
		- both after median
			* rrr
---
		- one on top, other before median
			* rb
		- one on top, other after median
			* rrb
---
		- one before median, other on top
			* ra
		- one after median, other on top
			* rra
---
		- one before median, other after
			* ra, rrb
		- one after median, other before
			* rra, rb
---
*/
size_t	best_to_top(t_move *move)
{
	size_t	cost;

	get_move(move);
	cost = move->a_move == move->b_move;
	cost += (2) * (cost == 0);
	cost -= (!move->a_move || !move->b_move) * (cost == 2);
	theoretic_move(move);
	return (cost);
}

// 1. Get which position the number goes in stack b
//		Ensure that the position is before a lower number
//			and after a bigger or the minimum number
size_t	pb_cost(t_data *stacks, size_t a_pos)
{
	t_move	move;
	size_t	cost;
	int		nbr;

	nbr = get_i(stacks->a, a_pos)->val;
	move_constructor(&move, stacks);
	move.a_pos = a_pos;
	move.b_pos = get_target_pos(stacks->b, nbr);
	cost = 0;
	while (move.b_pos || move.a_pos)
		cost += best_to_top(&move);
	cost++;
	return (cost);
}

// If bugs check lowest cost update equation
size_t	get_cheapest(t_data *stacks, size_t *target_pos)
{
	size_t	current_cost;
	size_t	lowest_cost;
	size_t	min_i;
	size_t	i;

	lowest_cost = -1;
	min_i = 0;
	i = 0;
	while (i < stacks->a_size)
	{
		current_cost = pb_cost(stacks, i);
		min_i = (i - min_i) * (current_cost < lowest_cost);
		lowest_cost += (current_cost - lowest_cost)
			* (current_cost < lowest_cost);
		i++;
	}
	if (target_pos)
		*target_pos = get_target_pos(stacks->b, get_i(stacks->a, min_i)->val);
	return (min_i);
}
