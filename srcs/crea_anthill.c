/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 12:07:30 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/19 16:18:30 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	is_ant_nb(char *s, t_hill *hill)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) != 1)
			return (-1);
		i++;
	}
	if (i == 0)
		return (-1);
	hill->nb_ant = ft_atoi(s);
	return (1);
}

static int	find_nb_rooms(char **data, t_hill *hill, int count)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	hill->nb_rooms = 0;
	while (i < count)
	{
		if (is_a_room(data[i]) == 1)
			hill->nb_rooms++;
		i++;
	}
	return (1);
}

static int	find_nb_link(char **data, t_hill *hill, int count)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	hill->nb_links = 0;
	while (i < count)
	{
		if (is_a_link(data[i]) == 1)
			hill->nb_links++;
		i++;
	}
	return (1);
}

int			crea_anthill(char **data, t_hill *hill, int count)
{
	if (is_ant_nb(data[0], hill) != 1)
	{
		ft_putendl("ERROR: There is no ants");
		return (-1);
	}
	if (find_nb_rooms(data, hill, count) == -1)
	{
		ft_putendl("ERROR: There is no rooms");
		return (-1);
	}
	if (find_nb_link(data, hill, count) == -1)
	{
		ft_putendl("ERROR: Wrong link found");
		return (-1);
	}
	if (crea_rooms(data, hill, count) == -1)
	{
		ft_putendl("ERROR");
		return (-1);
	}
	return (1);
}
