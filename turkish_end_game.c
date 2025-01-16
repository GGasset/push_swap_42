/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_end_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:37:59 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/16 13:07:52 by ggasset-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	int			i[2];

	sort_i = 0;
	just_bigger = 2147483647;
	iter = head;
	i[0] = 0;
	i[1] = 0;
	while (iter->contains_val && (iter != head || !i[0]))
	{
		i[1] += iter->val > nbr && iter->val < just_bigger;
		sort_i += (i[0] - sort_i) * (iter->val > nbr && iter->val < just_bigger);
		just_bigger += (iter->val - just_bigger)
			* (iter->val > nbr && iter->val < just_bigger);
		iter = iter->next;
		i[0]++;
	}
	if (!i[1])
		sort_i = get_min_i(head);
	return (sort_i);
}

void	print_list(t_crc_nd *head)
{
	t_crc_nd	*iter;
	int			i;

	iter = head;
	i = 0;
	while (iter->contains_val && (iter != head || !i))
	{
		ft_putnbr_fd(iter->val, 1);
		ft_putstr_fd("\n", 1);
		iter = iter->next;
		i++;
	}
}

int	get_rotation_move(size_t pos, t_move move, int is_a)
{
	int		rotation;
	int		direction;
	size_t	median;
	size_t	len;

	len = move.a_len * (is_a != 0) + move.median_b * !is_a;
	median = move.median_a * (is_a != 0) + move.median_b * !is_a;
	direction = 1 - 2 * (pos > median);
	rotation = pos;
	if (direction == -1)
		rotation = len - pos;
	rotation *= direction;
	return (rotation);
}

void	get_cheapest_pa(t_data *stacks, t_move *move)
{
	size_t		i;
	t_crc_nd	*iter;
	t_move		top_move;
	t_move		tmp_move;

	ft_memcpy(&top_move, move, sizeof(t_move));
	top_move.a_move = -2147483647;
	top_move.b_move = -2147483647;
	ft_memcpy(&tmp_move, &top_move, sizeof(t_move));
	i = 0;
	while (iter)
	{
		tmp_move.b_pos = i;
		tmp_move.b_move = get_rotation_move(i, *move, 0);
		tmp_move.a_pos = get_sorted_position(stacks->a, iter->val);
		tmp_move.a_move = get_rotation_move(tmp_move.a_pos, *move, 1);
		if (ft_abs(tmp_move.b_pos) + (long)ft_abs(tmp_move.a_move)
			< ft_abs(top_move.a_move) + (long)ft_abs(top_move.b_move))
			ft_memcpy(&top_move, &tmp_move, sizeof(t_move));
		iter = get_next_valued(stacks->b, iter, iter == stacks->b);
		i++;
	}
	ft_memcpy(move, &top_move, sizeof(move));
}
