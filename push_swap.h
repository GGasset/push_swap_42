/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:33:45 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/17 13:24:26 by ggasset-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "aio.h"
# include "stdlib.h"

# include "libft/libft.h"

typedef struct s_move
{
	size_t	a_len;
	size_t	b_len;
	size_t	a_pos;
	size_t	b_pos;
	size_t	median_a;
	size_t	median_b;
	int		a_move;
	int		b_move;
}		t_move;

typedef struct s_crc_nd
{
	struct s_crc_nd	*next;
	struct s_crc_nd	*prev;
	int			sorted_i;
	int			val;
	char		contains_val;
}		t_crc_nd;

typedef struct s_data
{
	t_crc_nd	*a;
	size_t		a_size;
	t_crc_nd	*b;
	size_t		b_size;
	int			mov_count;
}		t_data;

int			main(int argc, char *argv[]);
int			*parse_args(int argc, char **argv);
int			*check_args(int argc, char **argv);

void		k1(t_data *stacks);
void		k2(t_data *stacks);

void		bubble_sort(int *nbrs, size_t n, int ascending);
void		sort_three(t_data *stacks);
int			is_sorted(t_crc_nd *head, int ascending, int skip_empty);

void		print_list(t_crc_nd *head);
t_crc_nd	*intitialize_stack(int *nbrs, size_t value_count);
t_crc_nd	*circular_list_init(size_t node_count);
void		free_list(t_crc_nd **lst, size_t node_count);

size_t		get_max_value_i(t_crc_nd *head);
t_crc_nd	*get_next_valued(t_crc_nd *head, t_crc_nd *start, int head_start);
t_crc_nd	*get_prev_valued(t_crc_nd *start);
t_crc_nd	*get_last_valued(t_crc_nd *head);
t_crc_nd	*get_i(t_crc_nd *head, size_t i);

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
