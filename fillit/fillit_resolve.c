/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:09:53 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 14:13:03 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_dot_collision(t_fillit_dat *data)
{
	int idx;

	idx = -1;
	while (++idx < 4)
	{
		if (MAP[BLOCKS[idx] + P_IDX] != '.')
			return (1);
	}
	return (0);
}

static int	ft_tet_straddling(t_fillit_dat *data)
{
	if (((data->curr_node->p_idx) / data->map_size) <
		((data->curr_node->p_idx + data->curr_node->len) / data->map_size))
		return (1);
	return (0);
}

static int	ft_place_tet(t_fillit_dat *data)
{
	int		idx;

	while (data->map[P_IDX] && P_IDX < M_IDX)
	{
		if (!ft_tet_straddling(data) && !ft_dot_collision(data))
		{
			idx = -1;
			while (++idx < 4)
				data->map[BLOCKS[idx] + P_IDX] = data->curr_node->id;
			return (1);
		}
		P_IDX++;
	}
	return (0);
}

void		ft_resolve(t_fillit_dat *data)
{
	data->curr_node = data->head;
	while (data->curr_node)
	{
		if (ft_place_tet(data))
			data->curr_node = data->curr_node->next;
		else if (!M_IDX || data->head->p_idx >= H_M_IDX)
		{
			ft_clear_list(data->head);
			data->curr_node = data->head;
			data->map_size++;
			ft_make_map(data);
			ft_blocks_maker(data);
		}
		else
		{
			data->curr_node->p_idx = 0;
			data->curr_node = data->curr_node->prev;
			ft_clean_map_of_tet(data->map, data->curr_node);
			data->curr_node->p_idx++;
		}
	}
}
