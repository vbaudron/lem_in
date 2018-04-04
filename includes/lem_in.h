/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:41:48 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/19 16:14:51 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct	s_room
{
	char			*name;
	int				nb_links;
	int				is_start;
	int				is_end;
	struct s_room	**links;

}				t_room;

typedef struct	s_hill
{
	int				nb_ant;
	int				nb_rooms;
	int				nb_links;
	t_room			*start;
	t_room			*end;
	t_room			**tab;
}				t_hill;

typedef struct	s_ant_path
{
	t_room				*room;
	struct s_ant_path	*from;
	int					len;
	int					next_len;
	struct s_ant_path	**next;
}				t_ant_path;

typedef struct	s_ant_pos
{
	int		ant;
	int		pos;
	char	**order;
}				t_ant_pos;

int				crea_data(char ***data, int *count, char *s);
int				crea_anthill(char **data, t_hill *hill, int count);
int				is_a_room(char *s);
int				is_a_link(char *s);
int				crea_rooms(char **data, t_hill *hill, int count);
int				crea_links(char **data, t_hill *hill, int count);
int				link_it(char *data, t_hill *hill);
int				find_path(t_hill *hill, char *tmp);
int				is_already_in_path(t_ant_path *start, t_room *r_to_check);
int				handle_path(t_hill *hill, t_ant_path *path);
void			free_t_ant_path(t_ant_path **path);
void			free_hill(t_hill *hill);
char			**count_data_no_error(char **data, int *total, int i,
				int nb_room);
char			**new_data(char **data, int count);
char			**room_name(char **data, int total, char **name, int i);
t_ant_path		*new_path(t_ant_path *start, int i, t_ant_path **end_tab,
				int *end_found);
int				is_link_to_a_room(char *data, char **name, int nb_room, int i);

#endif
