/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:29:18 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/17 13:37:51 by ggasset-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		print_list(stacks->a);
		print_list(stacks->b);
		max_i = get_max_value_i(stacks->b);
		median = stacks->b_size / 2;
		is_reverse = max_i > median;
		max_i += ((stacks->b_size - max_i) - max_i) * is_reverse;
		if (!is_reverse)
			while (max_i)
			{
				rb(stacks, TRUE);
				max_i--;
			}
		else
			while (max_i)
			{
				rrb(stacks, TRUE);
				max_i--;
			}
		pa(stacks);
	}
}
