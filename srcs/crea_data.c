/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crea_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 11:59:18 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:50:10 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	len_line(char *s, int i)
{
	int	len;

	len = 0;
	while (s[i + len] != '\0' && s[i + len] != '\n')
		len++;
	return (len);
}

static char	*fullfill_data(char *s, int i, char *data)
{
	int	j;

	j = 0;
	while (s[i + j] != '\0' && s[i + j] != '\n')
	{
		data[j] = s[i + j];
		j++;
	}
	data[j] = '\0';
	return (data);
}

static int	check_data(char **data, int count, int has_end, int has_start)
{
	int	i;
	int	check_rooms;

	i = 0;
	check_rooms = 0;
	while (i < count)
	{
		if (i != 0 && ft_strrchr(data[i], ' ') == NULL &&
		data[i][0] != '#' && ft_strrchr(data[i], '-') == NULL)
			return (-3);
		if (ft_strcmp(data[i], "##end") == 0)
			has_end++;
		if (ft_strcmp(data[i], "##start") == 0)
			has_start++;
		if (is_a_room(data[i]) == 1)
			check_rooms++;
		i++;
	}
	if (check_rooms == 0)
		return (-2);
	if (has_start != 1 || has_end != 1)
		return (-1);
	return (1);
}

static int	what_error(int check)
{
	if (check == -2)
	{
		ft_putendl("ERROR: There is no rooms");
		return (-1);
	}
	else if (check == -1)
	{
		ft_putendl("ERROR: There is no Start or End room. Or too many !");
		return (-1);
	}
	else if (check == -3)
	{
		ft_putendl("ERROR: Map is not well formated");
		return (-1);
	}
	return (1);
}

int			crea_data(char ***data, int *count, char *s)
{
	int	i;
	int	j;
	int	len;
	int	check;

	i = 0;
	j = 0;
	len = 0;
	check = 0;
	while (i < *count)
	{
		len = len_line(s, j);
		(*data)[i] = malloc(sizeof(char) * (len + 1));
		if ((*data)[i] == NULL)
			return (-1);
		(*data)[i] = fullfill_data(s, j, (*data)[i]);
		j = j + len + 1;
		i++;
	}
	*data = count_data_no_error(*data, count, 0, 0);
	check = check_data(*data, *count, 0, 0);
	return (what_error(check));
}
