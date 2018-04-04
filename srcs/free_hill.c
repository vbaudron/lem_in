/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:40:06 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:06:24 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	free_room_content(t_room *room)
{
	int	i;

	i = 0;
	free(room->name);
	room->name = NULL;
	while (i < room->nb_links)
	{
		room->links[i] = NULL;
		i++;
	}
	free(room->links);
	room->links = NULL;
}

void		free_hill(t_hill *hill)
{
	int	i;

	i = 0;
	hill->start = NULL;
	hill->end = NULL;
	while (i < hill->nb_rooms)
	{
		free_room_content(hill->tab[i]);
		i++;
	}
	i = 0;
	while (i < hill->nb_rooms)
	{
		free(hill->tab[i]);
		i++;
	}
	free(hill->tab);
	hill->tab = NULL;
	free(hill);
	hill = NULL;
}
