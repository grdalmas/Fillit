/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:49:35 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 13:51:28 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_errors_manager(t_fillit_dat *data, int error)
{
	if (!data)
		ft_putstr("error");
	else if (!data->error && !error)
		return ;
	ft_putstr("error");
	if (DEBUG)
	{
		ft_putstr(" nb >");
		if (!error)
			ft_putnbr(data->error);
		else if (!data->error)
			ft_putnbr(error);
		ft_putstr("<");
		if (data->error == OPEN_FILE_ERR)
			ft_putnbr(data->ret_read);
	}
	ft_putstr("\n");
	ft_erazer(data);
	exit(0);
}
