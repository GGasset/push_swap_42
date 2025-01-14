/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:17:46 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/13 16:58:35 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_crc_nd	*intitialize_stack(int *nbrs, size_t value_count)
{
	t_crc_nd	*stack;
	t_crc_nd	*tmp;
	size_t		i;

	stack = circular_list_init(value_count);
	if (!stack)
		return (0);
	tmp = stack;
	i = value_count;
	while (i)
	{
		tmp->val = nbrs[i - 1];
		tmp->contains_val = TRUE;
		tmp = tmp->next;
		i--;
	}
	return (stack);
}

t_crc_nd	*circular_list_init(size_t node_count)
{
	t_crc_nd	*out;
	t_crc_nd	*tmp;
	size_t		i;

	out = ft_calloc(1, sizeof(t_crc_nd));
	tmp = out;
	i = 1;
	while (out && tmp && i < node_count)
	{
		tmp->next = ft_calloc(1, sizeof(t_crc_nd));
		if (tmp->next)
			tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (tmp)
	{
		tmp->next = out;
		out->prev = tmp;
	}
	else if (!tmp && out)
		free_list(&out, i);
	return (out);
}

void	free_list(t_crc_nd **lst, size_t node_count)
{
	t_crc_nd	*tmp;
	t_crc_nd	*tmp1;
	size_t		i;

	if (!lst)
		return ;
	if (!*lst)
		return ;
	tmp = *lst;
	i = 0;
	while (i < node_count && tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
		i++;
	}
	*lst = 0;
}

void	move_constructor(t_move *move, t_data *stacks)
{
	move->a_len = stacks->a_size;
	move->b_len = stacks->b_size;
	move->median_a = stacks->a_size / 2;
	move->median_b = stacks->b_size / 2;
}
