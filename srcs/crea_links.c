/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:00:42 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/17 15:23:19 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	count_room_link2(char *data, t_room **tab, t_hill *hill, int i)
{
	int	j;
	int	k;
	int	save_i;

	j = 0;
	k = 0;
	save_i = i;
	while (j < hill->nb_rooms && data[i] != '\0')
	{
		while (data[i + k] != '\0' && data[i + k] == tab[j]->name[k])
			k++;
		if (data[i + k] == '\0' && tab[j]->name[k] == '\0')
		{
			tab[j]->nb_links++;
			return (1);
		}
		else
		{
			i = save_i;
			k = 0;
			j++;
		}
	}
	return (-1);
}

static int	count_room_link(char *data, t_room **tab, t_hill *hill)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < hill->nb_rooms && data[i] != '-')
	{
		while (data[i] != '-' && data[i] == tab[j]->name[i])
			i++;
		if (data[i] == '-')
		{
			tab[j]->nb_links++;
			i++;
			return (count_room_link2(data, tab, hill, i));
		}
		else
		{
			i = 0;
			j++;
		}
	}
	return (-1);
}

static int	malloc_links(t_room **tab, int nb_rooms)
{
	int	i;

	i = 0;
	while (i < nb_rooms)
	{
		tab[i]->links = malloc(sizeof(t_room*) * tab[i]->nb_links);
		if (tab[i]->links == NULL)
			return (-1);
		i++;
	}
	return (1);
}

int			crea_links(char **data, t_hill *hill, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (is_a_link(data[i]) == 1)
			count_room_link(data[i], hill->tab, hill);
		i++;
	}
	if (malloc_links(hill->tab, hill->nb_rooms) == -1)
		return (-1);
	i = 0;
	while (i < count)
	{
		if (is_a_link(data[i]) == 1)
			link_it(data[i], hill);
		i++;
	}
	return (1);
}
