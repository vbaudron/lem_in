/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:00:53 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:20:53 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	add_to_end_tab(t_ant_path *path, t_ant_path **end_tab,
		int *end_found)
{
	if (*end_found == 0 || (*end_tab)->len >= path->len)
		*end_tab = path;
	if (*end_found == 0)
		*end_found = 1;
}

static int	how_many_already_in_path(t_ant_path *start, int nb_links)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = nb_links;
	while (i < start->room->nb_links)
	{
		if (is_already_in_path(start, start->room->links[i]) == 1)
			nbr--;
		i++;
	}
	return (nbr);
}

static int	initialized_path(t_ant_path *start, int i, t_ant_path **path)
{
	if (*path == NULL)
		return (-1);
	(*path)->room = start->room->links[i];
	(*path)->from = start;
	(*path)->len = start->len + 1;
	(*path)->next_len = 0;
	if ((*path)->room->is_end == 0)
	{
		(*path)->next_len = how_many_already_in_path(*path,
				(*path)->room->nb_links);
		if ((*path)->next_len > 0)
		{
			(*path)->next = malloc(sizeof(t_ant_path*) * (*path)->next_len);
			if ((*path)->next == NULL)
				return (-1);
		}
		else
			(*path)->next = NULL;
	}
	else
		(*path)->next = NULL;
	return (1);
}

t_ant_path	*new_path(t_ant_path *start, int i, t_ant_path **end_tab,
		int *end_found)
{
	t_ant_path	*path;
	int			j;
	int			k;

	j = 0;
	k = 0;
	path = malloc(sizeof(t_ant_path));
	if (initialized_path(start, i, &path) == -1)
		return (NULL);
	if (path->room->is_end == 0 && path->next_len > 0)
	{
		while (k < path->next_len && j < path->room->nb_links)
		{
			if (is_already_in_path(path, path->room->links[j]) == 0)
			{
				path->next[k] = new_path(path, j, end_tab, end_found);
				k++;
			}
			j++;
		}
	}
	else if (path->room->is_end == 1)
		add_to_end_tab(path, end_tab, end_found);
	return (path);
}
