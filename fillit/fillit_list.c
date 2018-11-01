/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:44:01 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 14:09:20 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_tet_len(t_f_list *node)
{
	int		idx;

	idx = -1;
	while (++idx < 4)
	{
		if (node->x[idx] > node->len)
			node->len = node->x[idx];
	}
}

static void		ft_node_filler(t_f_list *node, char *buff, char id)
{
	node->id = id;
	ft_get_xy(node, ft_crop_x(buff), ft_crop_y(buff), buff);
	ft_tet_len(node);
}

static void		ft_node_linker(t_fillit_dat *data, t_f_list *node)
{
	t_f_list *tmp;
	t_f_list *last;

	tmp = data->head;
	if (!(data->head))
		data->head = node;
	else
	{
		while (tmp)
		{
			last = tmp;
			tmp = tmp->next;
		}
		node->prev = last;
		last->next = node;
	}
}

void			ft_create_list(t_fillit_dat *data)
{
	int			idx;
	t_f_list	*node;

	idx = -1;
	node = NULL;
	while (++idx < data->tet_nb)
	{
		ft_check_tet(data, data->buff + (idx * 21));
		node = ft_fresh_node(data);
		ft_node_linker(data, node);
		ft_node_filler(node, (data->buff) + (idx * 21), idx + 'A');
	}
}
