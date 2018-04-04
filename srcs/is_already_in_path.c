/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_already_in_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:01:38 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/17 12:01:38 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_already_in_path(t_ant_path *start, t_room *r_to_check)
{
	t_ant_path	*elem;

	elem = start->from;
	while (elem->from != NULL)
	{
		if (elem->room == r_to_check)
			return (1);
		elem = elem->from;
	}
	if (elem->room == r_to_check)
		return (1);
	return (0);
}
