/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:49:00 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/16 01:52:17 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_fillit_dat	*ft_fresh_data(void)
{
	t_fillit_dat	*data;

	data = NULL;
	if (!(data = (t_fillit_dat*)ft_memalloc(sizeof(t_fillit_dat))))
		ft_errors_manager(NULL, ALLOC_DATA_ERR);
	if (!(data->buff = ft_strnew(1024)))
		ft_errors_manager(data, ALLOC_BUFF_ERR);
	return (data);
}

t_f_list		*ft_fresh_node(t_fillit_dat *data)
{
	t_f_list	*node;

	if (!(node = (t_f_list*)ft_memalloc(sizeof(t_f_list))))
		ft_errors_manager(data, ALLOC_NODE_ERR);
	if (!(node->x = (int*)malloc(sizeof(int) * 4)))
		ft_errors_manager(data, ALLOC_NODE_X_ERR);
	if (!(node->y = (int*)malloc(sizeof(int) * 4)))
		ft_errors_manager(data, ALLOC_NODE_Y_ERR);
	return (node);
}
