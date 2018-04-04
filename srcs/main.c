/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 10:49:37 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 17:16:29 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initialize_hill(t_hill *hill)
{
	hill->tab = NULL;
	hill->start = NULL;
	hill->end = NULL;
	hill->nb_rooms = 0;
	hill->nb_links = 0;
	hill->nb_ant = 0;
}

int		go_to_lem_in(int count, t_hill *hill, char *tmp)
{
	char	**data;
	int		kill;

	kill = 0;
	data = malloc(sizeof(char*) * count);
	if (data == NULL)
		kill = 1;
	if (kill == 0 && crea_data(&data, &count, tmp) == -1)
		kill = 1;
	if (kill == 0 && crea_anthill(data, hill, count) == -1)
		kill = 1;
	if (kill == 0)
		find_path(hill, tmp);
	if (data)
		ft_free_str2(&data, count);
	return (1);
}

int		main(void)
{
	char	*line;
	t_hill	*hill;
	char	*tmp;
	int		count;

	line = NULL;
	tmp = NULL;
	count = 0;
	hill = malloc(sizeof(t_hill));
	if (hill == NULL)
		return (-1);
	initialize_hill(hill);
	while (get_next_line(0, &line) != 0)
	{
		tmp = ft_strjoin_free(tmp, line);
		tmp = ft_stradd_c_end(tmp, '\n');
		count++;
	}
	if (line)
		free(line);
	go_to_lem_in(count, hill, tmp);
	free_hill(hill);
	free(tmp);
	return (1);
}
