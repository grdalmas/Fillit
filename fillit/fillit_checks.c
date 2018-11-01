/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:52:32 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 14:06:40 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_count_links(t_fillit_dat *data, char *tetri)
{
	int i;

	data->links = 0;
	i = -1;
	while (++i < T_SIZE)
	{
		if (tetri[i] != '#')
			continue;
		if (i < 20 && tetri[i + 1] == '#')
			data->links++;
		if (i < 15 && tetri[i + 5] == '#')
			data->links++;
		if (i > 0 && tetri[i - 1] == '#')
			data->links++;
		if (i > 4 && tetri[i - 5] == '#')
			data->links++;
	}
}

static void	ft_count_hdl(t_fillit_dat *data, char *tetri)
{
	int idx;

	idx = -1;
	data->hash = 0;
	data->lines = 0;
	data->dots = 0;
	while (++idx < T_SIZE - 1)
	{
		if (tetri[idx] == '#')
			data->hash++;
		else if (tetri[idx] == '.')
			data->dots++;
		else if (tetri[idx] == '\n')
			data->lines++;
	}
}

static void	ft_check_line_len(t_fillit_dat *data, char *tet)
{
	int idx;
	int line_len;

	idx = -1;
	line_len = 0;
	while (++idx < 20)
	{
		if (tet[idx] == '\n')
		{
			if (line_len != 4)
			{
				data->error = LINE_LEN_ERR;
				break ;
			}
			else
				line_len = 0;
		}
		else
			line_len++;
	}
}

void		ft_check_tet(t_fillit_dat *data, char *tet)
{
	ft_count_hdl(data, tet);
	if (data->hash != 4 || data->dots != 12 || data->lines != 4)
		ft_errors_manager(data, TET_FORMAT_ERR);
	ft_count_links(data, tet);
	if (data->links != 8 && data->links != 6)
		ft_errors_manager(data, TET_LINKS_ERR);
	ft_check_line_len(data, tet);
	ft_errors_manager(data, FALSE);
}

void		ft_check_the_read(t_fillit_dat *data)
{
	if (data->ret_read == -1)
		data->error = OPEN_A_FOLDER_ERR;
	if (((data->ret_read + 1) % 21) || !(data->ret_read < T_SIZE * MAX_T_NB))
		data->error = ENTRY_SIZE_ERR;
	ft_errors_manager(data, FALSE);
}
