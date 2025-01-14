/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:33:45 by ggasset-          #+#    #+#             */
/*   Updated: 2025/01/13 18:33:57 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		mech_turkish(t_data *stacks);

void		move_cheapest(t_data *stacks);
void		sort_three(t_data *stacks);
void		move_to_a(t_data *stacks);
void		rotate_a_to_finish(t_data *stacks);

size_t		get_r_count(size_t sorted_pos, t_move move, int *is_reverse);
size_t		get_sorted_position(t_crc_nd *head, int nbr);

size_t		get_cheapest(t_data *stacks, size_t *target_pos);
size_t		pb_cost(t_data *stacks, size_t a_pos);
size_t		best_to_top(t_move *move);
size_t		get_target_pos(t_crc_nd *head, int nbr);
void		get_move(t_move *move);
void		real_move(t_data *stacks, t_move *move);
void		theoretic_move(t_move *move);

int			is_sorted(t_crc_nd *head, int ascending, int skip_empty);

t_crc_nd	*intitialize_stack(int *nbrs, size_t value_count);
t_crc_nd	*circular_list_init(size_t node_count);
void		free_list(t_crc_nd **lst, size_t node_count);
void		move_constructor(t_move *move, t_data *stacks);

t_crc_nd	*get_next_valued(t_crc_nd *head, t_crc_nd *start, int head_start);
t_crc_nd	*get_prev_valued(t_crc_nd *start);
t_crc_nd	*get_last_valued(t_crc_nd *head);
t_crc_nd	*get_i(t_crc_nd *head, size_t i);
size_t		get_minimum_value_i(t_crc_nd *head);

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
