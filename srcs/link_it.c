/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:01:43 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:02:46 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		is_link_room(char *s, t_room *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '-' && s[i] == start->name[i])
		i++;
	if (s[i] == '-' && start->name[i] == '\0')
		return (1);
	while (s[i] != '-')
		i++;
	i++;
	while (s[i + j] != '\0' && s[i + j] == start->name[j])
		j++;
	if (s[j] == '\0' && start->name[j] == '\0')
		return (1);
	return (0);
}

static int		find_room_name(char *s, int i, t_hill *hill)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < hill->nb_rooms)
	{
		while (s[i + k] != '\0' && hill->tab[j]->name[k] != '\0' &&
		hill->tab[j]->name[k] == s[i + k])
			k++;
		if ((hill->tab[j]->name[k] == '\0' || hill->tab[j]->name[k] == '-')
		&& s[i + k] == '\0')
			return (j);
		j++;
		k = 0;
	}
	return (-1);
}

static int		link_second(t_room *linked, t_room *to_link)
{
	int	i;

	i = 0;
	while (i < to_link->nb_links && to_link->links[i] != NULL)
		i++;
	if (i == to_link->nb_links)
		return (-1);
	to_link->links[i] = linked;
	return (1);
}

static int		link_both(char *s, t_room *start, t_hill *hill)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < start->nb_links && start->links[i] != NULL
	&& start->links[i]->name != NULL)
		i++;
	while (s[j] == start->name[j])
		j++;
	k = find_room_name(s, j + 1, hill);
	if (k == -1)
		return (-1);
	start->links[i] = hill->tab[k];
	if (link_second(start, hill->tab[k]) == -1)
		return (-1);
	return (1);
}

int				link_it(char *data, t_hill *hill)
{
	int	i;

	i = 0;
	while (i < hill->nb_rooms)
	{
		if (is_a_link(data) && is_link_room(data, hill->tab[i]))
		{
			if (link_both(data, hill->tab[i], hill) == -1)
				return (-1);
		}
		i++;
	}
	return (1);
}
