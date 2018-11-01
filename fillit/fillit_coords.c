/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:59:29 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 14:01:45 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_crop_x(char *str)
{
	int ret;
	int idx;

	ret = 0;
	idx = 0;
	while (idx < 21 && str[idx] != '#')
	{
		idx += 5;
		if (idx > 19)
		{
			idx -= 19;
			ret++;
		}
	}
	return (ret);
}

int		ft_crop_y(char *str)
{
	int ret;
	int idx;

	ret = 0;
	idx = 0;
	while (idx < 21 && str[idx] != '#')
	{
		if (str[idx] == '\n')
			ret++;
		idx++;
	}
	return (ret);
}

void	ft_get_xy(t_f_list *node, int crop_x, int crop_y, char *str)
{
	int	i;
	int	hash_id;
	int line;

	hash_id = 0;
	i = -1;
	line = 0;
	while (++i < 21 && hash_id < 4)
	{
		if (str[i] == '#')
		{
			node->x[hash_id] = (i % 5) - crop_x;
			node->y[hash_id] = line - crop_y;
			hash_id++;
		}
		else if (str[i] == '\n')
			line++;
	}
}
