/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:32:18 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 18:20:58 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(t_win *win)
{
	if (win->map)
		free(win->map);
	ft_printf("\e[0;31mERROR\nMISCONFIGURATED MAP\n");
	exit(1);
}

int	check_file_type(char *file)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(0);
	i = 0;
	while (file[i] != '\0')
		i++;
	--i;
	if (!ft_strnstr(file, "maps/", 5))
		return (0);
	if (file[i] == 'r' && file[i - 1] == 'e' && file[i - 2] == 'b' && file[i
		- 3] == '.' && file[i - 4])
		return (1);
	else
		return (0);
}

int	check_walls(t_win win)
{
	int	i;

	i = 0;
	while (i < win.mapstr->w)
	{
		if (win.map[0][i] != '1' || win.map[win.mapstr->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < win.mapstr->h)
	{
		if (win.map[i][0] != '1' || win.map[1][win.mapstr->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	coordenada(t_win *win)
{
	int	x;
	int	y;

	y = -1;
	while (win->map[++y])
	{
		x = -1;
		while (win->map[y][++x])
		{
			if (win->map[y][x] == 'P')
			{
				win->player_x = x;
				win->player_y = y;
				return (1);
			}
		}
	}
	return (0);
}

int	check_errors(t_win *win)
{
	if (coordenada(win) && map_size(*win) && count_components(win)
		&& check_walls(*win) && check_components(win))
	{
		if (!handle_flood_fill(win))
			return (0);
		else
		{
			ft_printf("\e[0;31mMISCONFIGURATED MAP\n");
			return (1);
		}
	}
	else
	{
		map_error(win);
		return (1);
	}
	return (0);
}
