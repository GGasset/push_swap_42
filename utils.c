/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:50:06 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/11 16:04:25 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_crc_nd	*get_next_valued(t_crc_nd *head, t_crc_nd *start, int head_start)
{
	t_crc_nd	*tmp0;
	size_t		search_started;

	if (!head || !start)
		return (0);
	if (!head_start && start == head)
		return (0);
	tmp0 = start;
	search_started = FALSE;
	while ((!tmp0->contains_val && tmp0 != head) || !search_started)
	{
		tmp0 = tmp0->next;
		search_started = TRUE;
	}
	if (tmp0 == head && search_started)
		return (0);
	return (tmp0);
}

t_crc_nd	*get_prev_valued(t_crc_nd *start)
{
	t_crc_nd	*iter;

	iter = start->prev;
	while (iter != start && !iter->contains_val)
		iter = iter->prev;
	if (iter == start)
		iter = 0;
	return (iter);
}

t_crc_nd	*get_last_valued(t_crc_nd *head)
{
	t_crc_nd	*out;

	out = get_prev_valued(head);
	if (!out)
		out = head;
	return (out);
}

t_crc_nd	*get_i(t_crc_nd *head, size_t i)
{
	t_crc_nd	*out;

	out = head;
	while (i)
	{
		out = out->next;
		i--;
	}
	return (out);
}

size_t	get_max_i(t_crc_nd *head)
{
	int			max_value;
	size_t		max_value_i;
	size_t		i;
	t_crc_nd	*iter;

	iter = head;
	max_value = -2147483648;
	max_value_i = 0;
	i = 0;
	while (iter->contains_val && (i == 0 || iter != head))
	{
		max_value_i += (i - max_value_i) * (iter->val > max_value);
		max_value += (iter->val - max_value) * (iter->val > max_value);
		iter = iter->next;
		i++;
	}
	return (max_value_i);
}
