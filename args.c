/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:30:02 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/31 12:44:36 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*free_nbrs(int *nbrs)
{
	free(nbrs);
	return (0);
}

static int	check_dups(int *nbrs, size_t nbr_count)
{
	int		duplicate;
	size_t	i;
	size_t	j;

	duplicate = 0;
	i = 0;
	while (i < nbr_count && !duplicate)
	{
		j = i + 1;
		while (j < nbr_count && !duplicate)
		{
			duplicate = nbrs[i] == nbrs[j];
			j++;
		}
		i++;
	}
	return (duplicate);
}

int	*parse_args(int *argc, char **argv)
{
	int		*nbrs;
	int		err;
	size_t	i;

	argv = ft_expand_argv(argc, argv, " ", ' ');
	err = check_args(*argc, argv);
	nbrs = ft_calloc(*argc - 1, sizeof(int));
	err = err || !nbrs;
	err = err || !argv;
	i = 0;
	while (i < (size_t)argc[0] - 1 && !err)
	{
		nbrs[i] = ft_atoi_s(argv[i + 1], &err);
		i++;
	}
	ft_free_splitted(argv);
	if (err)
		return (free_nbrs(nbrs));
	if (check_dups(nbrs, *argc - 1))
		return (free_nbrs(nbrs));
	return (nbrs);
}

int	check_args(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	char	c;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (!ft_isdigit(c) && !(c == '-' || c == '+'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
