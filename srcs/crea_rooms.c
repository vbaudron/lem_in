/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:49:39 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/16 16:13:39 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	is_an_end(char **data, char i)
{
	while (i - 1 >= 0 && data[i - 1][0] == '#')
	{
		if (ft_strcmp(data[i - 1], "##end") == 0)
			return (1);
		i--;
	}
	return (0);
}

static int	is_a_start(char **data, char i)
{
	while (i - 1 >= 0 && data[i - 1][0] == '#')
	{
		if (ft_strcmp(data[i - 1], "##start") == 0)
			return (1);
		i--;
	}
	return (0);
}

static int	put_room_in_tab(char **data, int i, t_room *tab)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	tab->name = NULL;
	while (data[i][len] != ' ')
		len++;
	tab->name = malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (-1);
	while (data[i][j] != ' ')
	{
		tab->name[j] = data[i][j];
		j++;
	}
	tab->name[j] = '\0';
	tab->is_start = is_a_start(data, i);
	tab->is_end = is_an_end(data, i);
	tab->nb_links = 0;
	return (1);
}

int			crea_rooms(char **data, t_hill *hill, int count)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	hill->tab = malloc(sizeof(t_room*) * hill->nb_rooms);
	if (hill->tab == NULL)
		return (-1);
	while (i < count)
	{
		if (is_a_room(data[i]) == 1)
		{
			hill->tab[j] = malloc(sizeof(t_room));
			put_room_in_tab(data, i, hill->tab[j]);
			if (hill->tab[j]->is_start == 1)
				hill->start = hill->tab[j];
			if (hill->tab[j]->is_end == 1)
				hill->end = hill->tab[j];
			j++;
		}
		i++;
	}
	if (crea_links(data, hill, count) == -1)
		return (-1);
	return (1);
}
