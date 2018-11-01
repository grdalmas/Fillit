/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:07:01 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 14:08:19 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static	int		ft_sqrt_up(int nb)
{
	int ret;

	ret = 1;
	while ((ret * ret) < nb)
		ret++;
	return (ret);
}

void			ft_min_map_size(t_fillit_dat *data)
{
	data->map_size = ft_sqrt_up(data->tet_nb * 4);
}

void			ft_make_map(t_fillit_dat *data)
{
	int len;

	len = (data->map_size * data->map_size);
	if (data->map)
		free(data->map);
	data->map = ft_strnew(len);
	ft_memset(data->map, '.', len);
	data->map_len = len;
}

void			ft_pad_map(t_fillit_dat *data)
{
	char *tmp;

	tmp = ft_padder(data->map, '\n', data->map_size, 1);
	free(data->map);
	data->map = tmp;
}
