/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:56:00 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/29 15:09:56 by ggasset-         ###   ########.fr       */
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
			iter = get_next_valued(iter, iter, TRUE);
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

void	bubble_sort(int *nbrs, size_t n, int ascending)
{
	size_t	i;
	int		sorted;
	int		tmp;

	ascending = 1 - 2 * !ascending;
	sorted = FALSE;
	while (!sorted)
	{
		sorted = TRUE;
		i = 1;
		while (i < n)
		{
			sorted &= nbrs[i - 1] * ascending < nbrs[i] * ascending;
			if (nbrs[i - 1] * ascending > nbrs[i] * ascending)
			{
				tmp = nbrs[i - 1];
				nbrs[i - 1] = nbrs[i];
				nbrs[i] = tmp;
			}
			i++;
		}
	}
}
