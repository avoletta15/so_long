#include "so_long.h"

void	put_img(t_win *win, void *img, int x, int y)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img, x * 32, y * 32); 
}

void	create_img(t_win *win) 
{
	win->img->wall = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/tile.xpm", &win->mapstr->w, &win->mapstr->h);
	win->img->exit_o = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/exit_open.xpm", &win->mapstr->w, &win->mapstr->h);
	win->img->exit_c = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/exit_closed.xpm", &win->mapstr->w, &win->mapstr->h);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/player_f.xpm", &win->mapstr->w, &win->mapstr->h);
	win->img->collect = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/gems.xpm", &win->mapstr->w, &win->mapstr->h);
	win->img->back = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/background.xpm", &win->mapstr->w, &win->mapstr->h);
}

void	game_window(t_win *win) // initializing mlx program 
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window
		(win->mlx_ptr, win->mapstr->w * 32, win->mapstr->h * 32, "so_long");
	win->moves = 0;
	win->over = 0;
	create_img(win);
	draw_img(win);
}

// 3 functions 