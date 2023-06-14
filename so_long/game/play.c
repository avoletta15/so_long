#include "so_long.h"
#include "../mlx/mlx.h"

void	move_up(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/player_f.xpm", &win->mapstr->w, &win->mapstr->h);
	if(win->map[win->player_y - 1][win->player_x] != '1'
		&& (win->map[win->player_y - 1][win->player_x] != 'E'
		|| !win->mapstr->collect))
	{
		if(win->map[win->player_y - 1][win->player_x] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			//win->player_y--;
			win->map[win->player_y - 1][win->player_x] = 'P';
		}
		else if(win->map[win->player_y - 1][win->player_x] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			//win->player_y--;
			win->map[win->player_y - 1][win->player_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}

void	move_down(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/player_f.xpm", &win->mapstr->w, &win->mapstr->h);
	if(win->map[win->player_y + 1][win->player_x] != '1'
		&& (win->map[win->player_y + 1][win->player_x] != 'E'
	       	|| !win->mapstr->collect))
	{
		if(win->map[win->player_y + 1][win->player_x] == 'C')
		{
			win->mapstr->collect--;
		    win->map[win->player_y][win->player_x] = '0';
			//win->player_y++;
			win->map[win->player_y + 1][win->player_x] = 'P';
		}
		else if(win->map[win->player_y + 1][win->player_x] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			//win->player_y++;
			win->map[win->player_y + 1][win->player_x] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}

void    move_left(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/player_f.xpm", &win->mapstr->w, &win->mapstr->h);
	if(win->map[win->player_y][win->player_x - 1] != '1'
		&& (win->map[win->player_y][win->player_x - 1] != 'E'
		|| !win->mapstr->collect))
	{
		if(win->map[win->player_y][win->player_x - 1] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			//win->player_x--;
			win->map[win->player_y][win->player_x - 1] = 'P';
		}
		else if(win->map[win->player_y][win->player_x - 1] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			//win->player_x--;
			win->map[win->player_y][win->player_x - 1] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}
void	move_right(t_win *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img->player);
	win->img->player = mlx_xpm_file_to_image
		(win->mlx_ptr, "xpm/player_f.xpm", &win->mapstr->w, &win->mapstr->h);
	if(win->map[win->player_y][win->player_x + 1] != '1'
		&& (win->map[win->player_y][win->player_x + 1] != 'E'
		|| !win->mapstr->collect))
	{
		if(win->map[win->player_y][win->player_x + 1] == 'C')
		{
			win->mapstr->collect--;
			win->map[win->player_y][win->player_x] = '0';
			//win->player_x++;
			win->map[win->player_y][win->player_x + 1] = 'P';
		}
		else if(win->map[win->player_y][win->player_x + 1] == '0')
		{
			win->map[win->player_y][win->player_x] = '0';
			//win->player_x++;
			win->map[win->player_y][win->player_x + 1] = 'P';
		}
		else
			win->over = 1;
		win->moves++;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
	}
	draw_img(win);
}
