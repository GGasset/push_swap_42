/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:01:24 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/13 17:26:07 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_crc_nd *head, int ascending, int skip_empty)
{
	t_crc_nd	*iter;
	int			prev_nbr;
	int			nbr;

	ascending = ascending != 0;
	ascending -= !ascending;
	prev_nbr = head->val;
	if (skip_empty)
		iter = get_next_valued(head, head, TRUE);
	else
		iter = head->next;
	while (iter->contains_val && iter != head)
	{
		nbr = iter->val;
		if (nbr * ascending < prev_nbr * ascending)
			return (FALSE);
		prev_nbr = nbr;
		if (skip_empty)
			iter = get_next_valued(head, iter, FALSE);
		else
			iter = iter->next;
	}
	return (TRUE);
}

/*
 #### Total combinations of sorted position = 3 * 2 * 1 | 3!

 123
 312 -> ra  -> 123
 231 -> rra -> 123
 213 -> sa  -> 123
 132 -> sa  -> 312 -> ra  -> 123
 321 -> sa  -> 231 -> rra -> 123
*/
void	sort_three(t_data *stacks)
{
	if (is_sorted(stacks->a, TRUE, FALSE))
		return ;
	else if (is_sorted(stacks->a->next, TRUE, TRUE))
		ra(stacks, TRUE);
	else if (is_sorted(stacks->a->next->next, TRUE, TRUE))
		rra(stacks, TRUE);
	else
	{
		sa(stacks, TRUE);
		sort_three(stacks);
	}
}

size_t	get_min_i(t_crc_nd *head)
{
	int			min_value;
	size_t		min_value_i;
	size_t		i;
	t_crc_nd	*iter;

	iter = head;
	min_value = 2147483647;
	min_value_i = 0;
	i = 0;
	while (iter->contains_val && (i == 0 || iter != head))
	{
		min_value_i += (i - min_value_i) * (iter->val < min_value);
		min_value += (iter->val - min_value) * (iter->val < min_value);
		iter = iter->next;
		i++;
	}
	return (min_value_i);
}

// Gets the index of the node with nbr just smaller than nbr
size_t	get_target_pos(t_crc_nd *target_stack, int nbr)
{
	int		closest_nbr;
	size_t	closest_i;
	size_t	i;

	closest_nbr = -2147483648;
	closest_i = 0;
	i = 0;
	while (target_stack->contains_val)
	{
		closest_i += (i - closest_i)
			* (target_stack->val < nbr && target_stack->val > closest_nbr);
		closest_nbr += (target_stack->val - closest_nbr)
			* (target_stack->val < nbr && target_stack->val > closest_nbr);
		target_stack = target_stack->next;
		i++;
	}
	return (closest_i);
}

void	real_move(t_data *stacks, t_move *move)
{
	if (move->a_move == 1 && move->b_move == 1)
		rrr(stacks);
	else if (move->a_move == -1 && move->b_move == -1)
		rr(stacks);
	else
	{
		if (move->a_move == 1)
			rra(stacks, TRUE);
		else if (move->a_move == -1)
			ra(stacks, TRUE);
		if (move->b_move == 1)
			rrb(stacks, TRUE);
		else if (move->b_move == -1)
			rb(stacks, TRUE);
	}
	theoretic_move(move);
}
