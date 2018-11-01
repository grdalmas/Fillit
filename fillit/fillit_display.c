/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:59:05 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/16 02:00:55 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display_result(t_fillit_dat *data)
{
	ft_pad_map(data);
	ft_putendl(data->map);
}
