/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:00:53 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:08:10 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant_path	*crea_start_path(t_hill *hill, t_ant_path **end_tab,
		int *end_found)
{
	t_ant_path	*path;
	int			i;

	i = 0;
	path = malloc(sizeof(t_ant_path));
	if (path == NULL)
		return (NULL);
	path->room = hill->start;
	path->from = NULL;
	path->len = 0;
	path->next_len = path->room->nb_links;
	path->next = malloc(sizeof(t_ant_path*) * path->next_len);
	if (path->next == NULL)
		return (NULL);
	while (i < path->next_len)
	{
		path->next[i] = new_path(path, i, end_tab, end_found);
		i++;
	}
	return (path);
}

int					find_path(t_hill *hill, char *tmp)
{
	t_ant_path	*start_path;
	t_ant_path	*end_tab;
	int			end_found;

	start_path = NULL;
	end_found = 0;
	end_tab = NULL;
	if (hill->start == hill->end)
	{
		ft_putendl(tmp);
		return (1);
	}
	if ((start_path = crea_start_path(hill, &end_tab, &end_found)) == NULL)
		return (-1);
	if (end_found == 0)
	{
		ft_putendl("ERROR: No Path found");
		free_t_ant_path(&start_path);
		return (-1);
	}
	ft_putendl(tmp);
	handle_path(hill, end_tab);
	end_tab = NULL;
	free_t_ant_path(&start_path);
	return (1);
}
