/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:01:31 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:20:32 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	is_a_room(char *s)
{
	int	i;
	int space;

	i = 0;
	space = 0;
	if (ft_strchr(s, ' ') == NULL || s[i] == '#')
		return (0);
	while (s[i] != ' ')
		i++;
	space++;
	i++;
	while (ft_isdigit(s[i]) == 1)
		i++;
	if (s[i] == '\0' || s[i] != ' ')
		return (-1);
	i++;
	while (s[i] != '\0' && s[i] != ' ')
		i++;
	if (s[i] == ' ')
		space++;
	while (ft_isdigit(s[i]) == 1)
		i++;
	if (s[i] == '\0')
		return (1);
	return (-1);
}
