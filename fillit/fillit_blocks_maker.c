/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_blocks_maker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:42:28 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 13:44:37 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_blocks_maker(t_fillit_dat *data)
{
	t_f_list	*tmp;
	int			blocks_len;
	int			idx;

	tmp = data->head;
	while (tmp)
	{
		blocks_len = 0;
		idx = -1;
		if (tmp->blocks)
			free(tmp->blocks);
		tmp->blocks = ft_memalloc(sizeof(int) * 4);
		while (++idx < 4)
			tmp->blocks[idx] = X[idx] + (Y[idx] * data->map_size);
		blocks_len = tmp->blocks[3];
		tmp->max_idx = data->map_len - blocks_len;
		tmp = tmp->next;
	}
}
