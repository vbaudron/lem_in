/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_data_no_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:12:22 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 17:26:56 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	check_it(char **data, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		if (i != 0 && ft_strchr(data[i], ' ') == NULL && data[i][0] != '#'
		&& ft_strchr(data[i], '-') == NULL)
			return (i);
		i++;
	}
	return (i);
}

static int	are_links_correct(char **name, char **data, int *total, int nb_room)
{
	int	i;

	i = 0;
	while (i < *total)
	{
		if (is_a_link(data[i]) == 1)
		{
			if (is_link_to_a_room(data[i], name, nb_room, 0) != 1)
			{
				*total = i;
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

char		**count_data_no_error(char **data, int *total, int i, int nb_room)
{
	int		save_total;
	char	**name;
	char	**tmp;

	save_total = *total;
	*total = check_it(data, *total);
	while (i < *total)
	{
		if (is_a_room(data[i]) == 1)
			nb_room++;
		i++;
	}
	name = malloc(sizeof(char *) * nb_room);
	if (name == NULL)
		return (NULL);
	room_name(data, *total, name, 0);
	are_links_correct(name, data, total, nb_room);
	ft_free_str2(&name, nb_room);
	if (save_total > *total)
	{
		tmp = new_data(data, *total);
		ft_free_str2(&data, save_total);
		return (tmp);
	}
	return (data);
}
