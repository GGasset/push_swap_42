/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:18 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/30 17:13:08 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	k1(t_data *stacks)
{
	int	i;
	int	range;

	range = ft_sqrt(stacks->a_size) * 1.4;
	i = 0;
	while (stacks->a_size)
	{
		if (stacks->a->sorted_i <= i)
		{
			pb(stacks);
			rb(stacks, TRUE);
			i++;
		}
		else if (stacks->a->sorted_i <= i + range)
		{
			pb(stacks);
			i++;
		}
		else
			ra(stacks, TRUE);
	}
}

void	k2(t_data *stacks)
{
	size_t	max_i;
	size_t	median;
	int		is_reverse;

	while (stacks->b_size)
	{
		max_i = get_max_value_i(stacks->b, FALSE);
		median = stacks->b_size / 2;
		is_reverse = max_i > median;
		max_i += ((stacks->b_size - max_i) - max_i) * is_reverse;
		while (max_i && !is_reverse)
		{
			rb(stacks, TRUE);
			max_i--;
		}
		while (max_i && is_reverse)
		{
			rrb(stacks, TRUE);
			max_i--;
		}
		pa(stacks);
	}
}

static void	insertion_sort(t_data *stacks, size_t size)
{
	size_t	i;
	size_t	rot_count;
	int		reverse;

	i = 0;
	while (i < size - 3)
	{
		rot_count = get_max_value_i(stacks->a, TRUE);
		reverse = rot_count > stacks->a_size / 2;
		if (reverse)
			rot_count = stacks->a_size - rot_count;
		while (rot_count)
		{
			if (reverse)
				rra(stacks, TRUE);
			else
				ra(stacks, TRUE);
			rot_count--;
		}
		pb(stacks);
		i++;
	}
	sort_three(stacks);
	while (i--)
		pa(stacks);
}

void	sort(t_data *stacks)
{
	size_t	size;

	size = stacks->a_size;
	if (size <= 3)
		sort_three(stacks);
	else if (size <= 7)
		insertion_sort(stacks, size);
	else
	{
		k1(stacks);
		k2(stacks);
	}
}
