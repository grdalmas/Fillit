/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:56:35 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 14:03:30 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_count_tet(t_fillit_dat *data)
{
	int ret;
	int rest;

	ret = data->ret_read / 21;
	rest = data->ret_read % 21;
	if (rest == 20)
		ret++;
	return (ret);
}

static void		ft_open_file(t_fillit_dat *data)
{
	data->fd = open(data->path, O_RDONLY);
	if (data->fd == -1)
		data->error = OPEN_FILE_ERR;
	ft_errors_manager(data, FALSE);
}

static void		ft_fill_buff(t_fillit_dat *data)
{
	data->ret_read = read(data->fd, data->buff, 1023);
	ft_check_the_read(data);
}

void			ft_file_treatement(t_fillit_dat *data)
{
	ft_open_file(data);
	ft_fill_buff(data);
	close(data->fd);
	data->tet_nb = ft_count_tet(data);
}
