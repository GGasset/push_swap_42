/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_end_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:37:59 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/13 18:56:25 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_r_count(size_t sorted_pos, t_move move, int *is_reverse)
{
	size_t	rotation_count;

	*is_reverse = sorted_pos > move.median_a;
	if (*is_reverse)
		rotation_count = move.a_len - sorted_pos;
	else
		rotation_count = sorted_pos;
	return (rotation_count);
}

size_t		get_sorted_position(t_crc_nd *head, int nbr)
{
	t_crc_nd	*iter;
	size_t		sort_i;
	int			just_bigger;
	int			i;

	sort_i = 0;
	just_bigger = -2147483648;
	iter = head;
	i = 0;
	while (iter->contains_val && (iter != head || !i))
	{
		sort_i += (i - sort_i) * (iter->val > nbr && iter->val < just_bigger);
		just_bigger += (iter->val - just_bigger)
			* (iter->val > nbr && iter->val < just_bigger);
		iter = iter->next;
		i++;
	}
	return (sort_i);	
}
