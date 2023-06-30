#include "so_long.h"

void	put_player(t_win *win, int x, int y)
{
	win->player_x = x;
	win->player_y = y;
	if(!win->over)
		put_img(win, win->img->player, x, y);
	else
		exit_game(win); //put_img(win, win->img->back, x, y);
}

 void	create_exit(t_win *win, int x, int y)
{
	if(win->mapstr->collect != 0)
		put_img(win, win->img->exit_c, x, y);
	else
		put_img(win, win->img->exit_o, x, y);
} 

void	draw_img(t_win *win)
{
	
	int	x;
	int	y;

	y = -1;
	while(win->map[++y])
	{
		x = -1;
		while(win->map[y][++x])
		{
			if (win->map[y][x] == '1')
				put_img(win, win->img->wall, x, y);
			else if (win->map[y][x] == '0')
				put_img(win, win->img->back, x, y);
			else if (win->map[y][x] == 'E')
				create_exit(win, x, y);
			else if (win->map[y][x] == 'P')
			{
				put_player(win, x, y);
				ft_printf("\nCOORDENADA DRAW_IMG:\n");
				ft_printf("PLAYER_X = %d\n", x);
				ft_printf("PLAYER_Y = %d\n", y);
			}
			else if (win->map[y][x] == 'C')
				put_img(win, win->img->collect, x, y); 
		}
	}
}

// 3 functions
