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
