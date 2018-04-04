/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 13:30:36 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:40:51 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	is_a_link(char *s)
{
	int	i;
	int	tiret;

	i = 0;
	tiret = 0;
	if (ft_strchr(s, '-') == NULL || s[i] == '#')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			tiret++;
		i++;
	}
	if (tiret != 1)
		return (-1);
	return (1);
}
