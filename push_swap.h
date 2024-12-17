/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:33:45 by ggasset-          #+#    #+#             */
/*   Updated: 2024/12/17 16:59:08 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "aio.h"
# include "stdlib.h"

# include "libft/libft.h"

typedef struct s_crc_nd
{
	t_crc_nd	*next;
	t_crc_nd	*prev;
	int			val;
	char		contains_val;
}		t_crc_nd;

typedef struct s_data
{
	t_crc_nd	*a;
	t_crc_nd	*b;
	int			mov_count;
}		t_data;

int			main(int argc, char *argv[]);
t_crc_nd	*intitialize_stack(int *nbrs, size_t value_count);
t_crc_nd	*circular_list_init(size_t node_count);
void		set_value(t_crc_nd *lst, size_t i, int val);
void		free_list(t_crc_nd *lst);

t_crc_nd	*get_next_valued(t_crc_nd *head, t_crc_nd *start, int head_start);

void		sa(t_data *stacks, int write_instruction);
void		sb(t_data *stacks, int write_instruction);
void		ss(t_data *stacks);
void		pa(t_data *stacks);
void		pb(t_data *stacks);
void		ra(t_data *stacks, int write_instruction);
void		rb(t_data *stacks, int write_instruction);
void		rr(t_data *stacks);
void		rra(t_data *stacks, int write_instruction);
void		rrb(t_data *stacks, int write_instruction);
void		rrr(t_data *stacks);

#endif
