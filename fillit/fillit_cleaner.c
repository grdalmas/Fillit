/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 01:55:18 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/16 01:56:07 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_map_of_tet(char *map, t_f_list *node)
{
	int idx;
	int erazed_char;

	idx = 0;
	erazed_char = 0;
	while (map[idx] && erazed_char < 4)
	{
		if (map[idx] == node->id)
		{
			map[idx] = '.';
			erazed_char++;
		}
		idx++;
	}
}

void	ft_clear_list(t_f_list *head)
{
	t_f_list *node;

	node = head;
	while (node)
	{
		node->p_idx = 0;
		node = node->next;
	}
}
