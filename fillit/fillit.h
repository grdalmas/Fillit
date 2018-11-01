/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grdalmas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 13:45:02 by grdalmas          #+#    #+#             */
/*   Updated: 2017/12/30 13:49:11 by grdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# ifndef PP_MACROS
#  define PP_MACROS
#  define TRUE 1
#  define FALSE 0
#  define DEBUG 0
#  define DEBUG_MODE 0
#  define VERBOSE_MODE 0
#  define STANDARD_MODE 0
#  define ERROR_EXIT 0
#  define STANDARD_EXIT 1
#  define RET_READ_ERR 1
# endif
# include "libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define T_SIZE 21
# define MAX_T_NB 26
# define TET_FORMAT_ERR 84987
# define TET_LINKS_ERR 4545
# define ENTRY_SIZE_ERR 6987
# define LINE_LEN_ERR 7777
# define OPEN_FILE_ERR 1111
# define OPEN_A_FOLDER_ERR 6988
# define ALLOC_DATA_ERR 1212
# define ALLOC_NODE_ERR 1313
# define ALLOC_BUFF_ERR 1414
# define ALLOC_NODE_TC_ERR 1515
# define ALLOC_NODE_X_ERR 1616
# define ALLOC_NODE_Y_ERR 1717
# define P_IDX data->curr_node->p_idx
# define M_IDX data->curr_node->max_idx
# define H_M_IDX data->head->max_idx
# define MAP data->map
# define BLOCKS data->curr_node->blocks
# define X tmp->x
# define Y tmp->y

typedef struct				s_f_list
{
	char					id;
	int						*x;
	int						*y;
	int						*blocks;
	int						len;
	int						p_idx;
	int						max_idx;
	struct s_f_list			*next;
	struct s_f_list			*prev;
}							t_f_list;

typedef struct				s_fillit_dat
{
	int						error;
	int						tet_nb;
	int						ret_read;
	int						map_size;
	int						map_len;
	int						fd;
	char					dots;
	char					hash;
	char					links;
	char					lines;
	struct s_f_list			*head;
	struct s_f_list			*curr_node;
	char					*path;
	char					*buff;
	char					*map;
}							t_fillit_dat;

/*
** fillit_blocks_maker.c
*/

void						ft_blocks_maker(t_fillit_dat *data);

/*
** fillit_checks.c
*/

void						ft_check_the_read(t_fillit_dat *data);
void						ft_check_tet(t_fillit_dat *data, char *tet);

/*
** fillit_cleaner.c
*/

void						ft_clear_list(t_f_list *head);
void						ft_clean_map_of_tet(char *map, t_f_list *node);

/*
** fillit_coords.c
*/

int							ft_crop_x(char *str);
int							ft_crop_y(char *str);
void						ft_get_xy(t_f_list *node, int crop_x, int crop_y,
										char *str);

/*
**	fillit_display.c
*/

void						ft_display_result(t_fillit_dat *data);

/*
**	fillit_erazer.c
*/

void						ft_erazer(t_fillit_dat *data);

/*
**	fillit_errors.c
*/
void						ft_errors_manager(t_fillit_dat *data, int error);

/*
**	fillit_files.c
*/

void						ft_file_treatement(t_fillit_dat *data);

/*
**	fillit_init.c
*/

t_fillit_dat				*ft_fresh_data(void);
t_f_list					*ft_fresh_node(t_fillit_dat *data);

/*
**	fillit_list.c
*/
void						ft_create_list(t_fillit_dat *data);

/*
**	fillit_map.c
*/

void						ft_make_map(t_fillit_dat *data);
void						ft_min_map_size(t_fillit_dat *data);
void						ft_pad_map(t_fillit_dat *data);

/*
**	fillit_resolve.c
*/

void						ft_resolve(t_fillit_dat *data);

#endif
