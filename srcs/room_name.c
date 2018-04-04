/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:03:27 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/19 16:16:36 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**room_name(char **data, int total, char **name, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (i < total)
	{
		if (is_a_room(data[i]) == 1)
		{
			while (data[i][j] != ' ')
				j++;
			name[k] = ft_strnew(j + 1);
			j = 0;
			while (data[i][j] != ' ')
			{
				name[k][j] = data[i][j];
				j++;
			}
			name[k][j] = '\0';
			k++;
			j = 0;
		}
		i++;
	}
	return (name);
}
