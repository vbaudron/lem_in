/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 12:01:10 by vbaudron          #+#    #+#             */
/*   Updated: 2017/10/18 16:13:26 by vbaudron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		print_one(t_ant_pos *ants, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar('L');
		ft_putnbr(ants[i].ant);
		ft_putchar('-');
		ft_putstr(ants[i].order[0]);
		if (i != len - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

static void		print_this(t_ant_pos *ants, int len, int i, int order_len)
{
	int	j;

	j = 0;
	ft_putchar('L');
	ft_putnbr(ants[i].ant);
	ft_putchar('-');
	ft_putstr(ants[i].order[ants[i].pos]);
	if (i + 1 < len && ants[i + 1].pos >= 0 && ants[i + 1].pos < order_len)
		ft_putchar(' ');
}

static void		print_all(t_ant_pos *ants, int len, int order_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (order_len == 1)
		print_one(ants, len);
	else
	{
		while (ants[len - 1].pos < order_len)
		{
			while (i < len)
			{
				if (ants[i].pos >= 0 && ants[i].pos < order_len)
					print_this(ants, len, i, order_len);
				ants[i].pos = ants[i].pos + 1;
				i++;
				j = 0;
			}
			i = 0;
			ft_putchar('\n');
		}
	}
}

static void		fullfill_ant_pos(t_ant_pos *ants, int len, char **order)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ants[i].ant = i + 1;
		ants[i].pos = 0 - i;
		ants[i].order = order;
		i++;
	}
}

int				handle_path(t_hill *hill, t_ant_path *path)
{
	char		**order;
	int			len;
	t_ant_pos	*ants;
	t_ant_path	*elem;

	len = path->len;
	elem = path;
	order = malloc(sizeof(char*) * len);
	ants = malloc(sizeof(t_ant_pos) * hill->nb_ant);
	if (order == NULL || ants == NULL)
		return (-1);
	while (--len >= 0)
	{
		order[len] = malloc(sizeof(char) * (ft_strlen(elem->room->name) + 1));
		order[len] = ft_strcpy(order[len], elem->room->name);
		if (len != 0)
			elem = elem->from;
	}
	fullfill_ant_pos(ants, hill->nb_ant, order);
	print_all(ants, hill->nb_ant, path->len);
	ft_free_str2(&order, path->len);
	free(ants);
	ants = NULL;
	elem = NULL;
	return (1);
}
