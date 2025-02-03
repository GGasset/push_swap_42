/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:17:46 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/29 15:06:05 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_sorted_pos(t_crc_nd *stack, int *nbrs, size_t value_count)
{
	int		*nbrs_cp;
	size_t	j;
	size_t	i;

	nbrs_cp = malloc(value_count * sizeof(int));
	ft_memcpy(nbrs_cp, nbrs, value_count * sizeof(int));
	bubble_sort(nbrs_cp, value_count, TRUE);
	i = 0;
	while (i < value_count)
	{
		j = 0;
		while (stack->val != nbrs_cp[j])
			j++;
		stack->sorted_i = j;
		stack = stack->next;
		i++;
	}
	free(nbrs_cp);
}

t_crc_nd	*intitialize_stack(int *nbrs, size_t value_count)
{
	t_crc_nd	*stack;
	t_crc_nd	*tmp;
	size_t		i;

	stack = circular_list_init(value_count);
	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	while (i < value_count)
	{
		tmp->val = nbrs[i];
		tmp->contains_val = TRUE;
		tmp = tmp->next;
		i++;
	}
	set_sorted_pos(stack, nbrs, value_count);
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
