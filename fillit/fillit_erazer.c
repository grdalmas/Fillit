/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_erazer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 02:05:35 by grdalmas          #+#    #+#             */
/*   Updated: 2018/01/08 17:57:17 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void		ft_eraze_node(t_f_list *node)
{
	if (!node)
		return ;
	free(node->blocks);
	node->blocks = NULL;
	free(node->y);
	node->y = NULL;
	free(node->x);
	node->x = NULL;
	free(node);
}

static void		ft_eraze_list(t_f_list *head)
{
	t_f_list	*node;
	t_f_list	*prev_node;

	node = head;
	if (!node)
		return ;
	while (node->next)
		node = node->next;
	prev_node = node->prev;
	while (node)
	{
		ft_eraze_node(node);
		if (!prev_node)
			break ;
		node = prev_node;
		prev_node = node->prev;
	}
}

static void		ft_eraze_data(t_fillit_dat *data)
{
	if (!data)
		return ;
	free(data->map);
	data->map = NULL;
	free(data->buff);
	data->buff = NULL;
	free(data);
}

void			ft_erazer(t_fillit_dat *data)
{
	ft_eraze_list(data->head);
	ft_eraze_data(data);
}
