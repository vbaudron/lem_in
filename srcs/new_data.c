/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:05:00 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:05:22 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**new_data(char **data, int total)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char*) * total);
	if (new == NULL)
		return (NULL);
	while (i < total)
	{
		new[i] = ft_strdup(data[i]);
		i++;
	}
	return (new);
}
