/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_ant_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:15:21 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:07:09 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_t_ant_path(t_ant_path **path)
{
	int	i;

	i = 0;
	(*path)->room = NULL;
	(*path)->from = NULL;
	while (i < (*path)->next_len)
	{
		free_t_ant_path(&(*path)->next[i]);
		free((*path)->next[i]);
		(*path)->next[i] = NULL;
		i++;
	}
	if ((*path)->next)
		free((*path)->next);
	(*path)->next = NULL;
	free(*path);
	*path = NULL;
}
