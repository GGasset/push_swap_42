/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_funcs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggasset- <ggasset-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:42:39 by ggasset-          #+#    #+#             */
/*   Updated: 2024/10/28 18:45:25 by ggasset-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_FUNCS_H
# define STRUCTURE_FUNCS_H

t_crc_nd	*circular_list_init(size_t node_count);
void		set_value(t_crc_nd *this, size_t i, int val);

#endif
