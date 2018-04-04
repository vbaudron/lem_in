/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link_to_a_room.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:13:18 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/19 16:16:10 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	is_linked_to_a_room_2(char *data, char **name, int nb_room, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (j < nb_room)
	{
		while (data[i + k] != '\0' && name[j][k] != '\0' && data[i + k]
		== name[j][k])
			k++;
		if (name[j][k] == '\0' && data[i + k] == '\0')
			return (1);
		j++;
		k = 0;
	}
	return (0);
}

int	is_link_to_a_room(char *data, char **name, int nb_room, int i)
{
	int j;

	j = 0;
	while (j < nb_room)
	{
		while (data[i] == name[j][i])
			i++;
		if (name[j][i] == '\0' && data[i] == '-')
			return (is_linked_to_a_room_2(data, name, nb_room, i + 1));
		i = 0;
		j++;
	}
	return (0);
}
