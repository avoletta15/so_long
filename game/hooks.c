/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:33:28 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/06 16:07:08 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_win *win)
{
	free_map(win->map);
	mlx_destroy_image(win->mlx_ptr, win->img->wall);
	mlx_destroy_image(win->mlx_ptr, win->img->exit_o);
	mlx_destroy_image(win->mlx_ptr, win->img->exit_c);
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	mlx_destroy_image(win->mlx_ptr, win->img->collect);
	mlx_destroy_image(win->mlx_ptr, win->img->back);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->img);
	free(win->mlx_ptr);
	free(win->mapstr);
	exit(0);
}

int	read_esc(int keycode, t_win *win)
{
	if (keycode == K_ESC)
		exit_game(win);
	return (0);
}

int	key_hooks(int keycode, t_win *win)
{
	int	counter;

	counter = win->moves;
	if (win->over)
		return (0);
	if (keycode == K_UP || keycode == A_UP)
		move_up(win);
	else if (keycode == K_LEFT || keycode == A_LEFT)
		move_left(win);
	else if (keycode == K_DOWN || keycode == A_DOWN)
		move_down(win);
	else if (keycode == K_RIGHT || keycode == A_RIGHT)
		move_right(win);
	if (counter != win->moves)
		ft_printf("Moves: %d\n", win->moves);
	return (0);
}

// 3 functions