/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:50:06 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/16 18:00:14 by ggasset-         ###   ########.fr       */
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
	while (!tmp0->contains_val && (tmp0 != head || (!search_started)))
	{
		tmp0 = tmp0->next;
		search_started = TRUE;
	}
	if (tmp0 == head && search_started)
		return (0);
	return (tmp0);
}