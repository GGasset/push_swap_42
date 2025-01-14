/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:02:26 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/11 16:41:47 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			*nbrs;
	t_data		stacks;
	t_crc_nd	*tmp_pntr;

	nbrs = parse_args(argc, argv);
	if (!nbrs || (size_t)nbrs == 1)
	{
		if (!nbrs)
			ft_putendl_fd("Error", 2);
		return (0);
	}
	ft_bzero(&stacks, sizeof(t_data));
	stacks.a = intitialize_stack(nbrs, argc - 1);
	stacks.a_size = argc - 1;
	stacks.b = circular_list_init(argc - 1);
	free(nbrs);
	mech_turkish(&stacks);
	tmp_pntr = stacks.a;
	free_list(&tmp_pntr, argc - 1);
	tmp_pntr = stacks.b;
	free_list(&tmp_pntr, argc - 1);
	return (0);
}
