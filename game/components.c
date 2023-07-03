/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:25:42 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:30:07 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_win *win, void *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img, x * 32, y * 32);
}

void	create_img(t_win *win)
{
	win->img->wall = mlx_xpm_file_to_image(win->mlx_ptr, "xpm/tile.xpm",
			&win->mapstr->w, &win->mapstr->h);
	win->img->exit_o = mlx_xpm_file_to_image(win->mlx_ptr, "xpm/exit_open.xpm",
			&win->mapstr->w, &win->mapstr->h);
	win->img->exit_c = mlx_xpm_file_to_image(win->mlx_ptr,
			"xpm/exit_closed.xpm", &win->mapstr->w, &win->mapstr->h);
	win->img->player = mlx_xpm_file_to_image(win->mlx_ptr, "xpm/player_f.xpm",
			&win->mapstr->w, &win->mapstr->h);
	win->img->collect = mlx_xpm_file_to_image(win->mlx_ptr, "xpm/gems.xpm",
			&win->mapstr->w, &win->mapstr->h);
	win->img->back = mlx_xpm_file_to_image(win->mlx_ptr, "xpm/background.xpm",
			&win->mapstr->w, &win->mapstr->h);
}

int	check_components(t_win *win)
{
	int	y;
	int	x;

	if (!win->map)
		return (0);
	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] != 'P' && win->map[y][x] != 'C'
				&& win->map[y][x] != 'E' && win->map[y][x] != '1'
				&& win->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	count_components(t_win *win)
{
	int	h;
	int	w;

	win->mapstr->player = 0;
	win->mapstr->collect = 0;
	win->mapstr->exit = 0;
	w = 0;
	while (w < win->mapstr->w)
	{
		h = -1;
		while (++h < win->mapstr->h)
		{
			if (win->map[h][w] == 'P')
				win->mapstr->player++;
			if (win->map[h][w] == 'C')
				win->mapstr->collect++;
			if (win->map[h][w] == 'E')
				win->mapstr->exit++;
		}
		w++;
	}
	if (win->mapstr->exit != 1 || !win->mapstr->collect
		|| win->mapstr->player != 1)
		return (0);
	return (1);
}

void	game_window(t_win *win)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->mapstr->w * 32,
			win->mapstr->h * 32, "so_long");
	win->moves = 0;
	win->over = 0;
	create_img(win);
	draw_img(win);
}
