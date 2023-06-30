#include "so_long.h"


void	map_error(t_win *win)
{
	if(win->map)
		free(win->map);
	ft_printf("\e[0;31mERROR\nMISCONFIGURATED MAP\n");
	exit(1);
}

int	check_file_type(char *file)
{
	int	i;
	
	i = 0;
	while (file[i] != '\0')
		i++;
	--i;
	if(file[i] == 'r' && file[i - 1] == 'e'
		&& file[i - 2] == 'b' && file[i - 3] == '.'
		&& file[i - 4])
		return (1);
	else
		return (0);
}

int	check_components(t_win *win)
{
	int	h;
	int	w;

	win->mapstr->player = 0;
	win->mapstr->collect = 0;
	win->mapstr->exit = 0;
	w = 0;
	while(w < win->mapstr->w)
	{
		h = 0;
		while(h < win->mapstr->h)
		{
			if(win->map[h][w] == 'P')
				 win->mapstr->player++;
			if(win->map[h][w] == 'C')
				win->mapstr->collect++;
			if(win->map[h][w] == 'E')
				win->mapstr->exit++;
			h++;
		}
		w++;
	}
	if(win->mapstr->exit != 1 || !win->mapstr->collect || win->mapstr->player != 1)
		return (0);
	return (1);
}

int	check_walls(t_win win)
{
	int	i;
	
	i = 0;
	while(i < win.mapstr->w)
	{
		if(win.map[0][i] != '1' || win.map[win.mapstr->h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(i < win.mapstr->h)
	{
		if(win.map[i][0] != '1' || win.map[1][win.mapstr->w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	coordenada (t_win *win)
{
	int	x;
	int	y;

	y = -1;
	while(win->map[++y])
	{
		x = -1;
		while(win->map[y][++x])
		{
			if (win->map[y][x] == 'P')
			{
				win->player_x = x;
				win->player_y = y;
				return (1);
			}
		}
	}
	return(0);				
}

int	check_errors(t_win *win)
{
	int y;
	int x;
	if(!win->map)
		return (0);
	y = 0;
	while(win->map[y])
	{
		x = 0;
		while(win->map[y][x])
		{
			if(win->map[y][x] != 'P' && win->map[y][x] != 'C'
				&& win->map[y][x] != 'E' && win->map[y][x] != '1'
				&& win->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	
	if(coordenada(win) && map_size(*win) && check_components(win) && check_walls(*win))
	{
		if(!handle_flood_fill(win))
			return(0);
		else
			ft_printf("\e[0;31mMISCONFIGURATED MAP\n");
			return (1);
	}
	else
	{
		map_error(win);
		return (1);
	}
	return (0);
}

// 5 functions
