/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:39:11 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 13:41:32 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_print_usage(void)
{
	ft_putendl("usage : ./fillit path_of_tetriminos_file");
}

int					main(int ac, char **av)
{
	t_fillit_dat	*data;

	data = NULL;
	if (ac == 2)
	{
		data = ft_fresh_data();
		data->path = av[1];
		ft_file_treatement(data);
		ft_create_list(data);
		ft_min_map_size(data);
		ft_make_map(data);
		ft_blocks_maker(data);
		ft_resolve(data);
		ft_display_result(data);
	}
	else
		ft_print_usage();
	return (0);
}
