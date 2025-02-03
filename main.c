/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:02:26 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/30 17:02:12 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("\n", 1);
}

int	main(int argc, char *argv[])
{
	int			*nbrs;
	t_data		stacks;
	t_crc_nd	*tmp_pntr;

	nbrs = parse_args(&argc, argv);
	if (!nbrs)
	{
		write(2, "Error\n", 7 * (argc > 1));
		return (0);
	}
	ft_bzero(&stacks, sizeof(t_data));
	stacks.a = intitialize_stack(nbrs, argc - 1);
	stacks.a_size = argc - 1;
	stacks.b = circular_list_init(argc - 1);
	free(nbrs);
	if (!is_sorted(stacks.a, TRUE, FALSE))
		sort(&stacks);
	tmp_pntr = stacks.a;
	free_list(&tmp_pntr, argc - 1);
	tmp_pntr = stacks.b;
	free_list(&tmp_pntr, argc - 1);
	return (0);
}
