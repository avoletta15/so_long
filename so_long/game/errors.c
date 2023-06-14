#include "so_long.h"
#include "../mlx/mlx.h"

int	map_size(char **map, t_map *mapstr)
{
	int	w;
	int	h;
	//int	check;

	w = 0;
	h = 0;
	while (map[h])
	{
		w = 0;
		while(map[h][w])
			w++;
		h++;
	}
	if (h < 3 || (h && h == w))
		return(0);
	mapstr->h = h;
	mapstr->w = w;
	return (1);
}

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

int	check_components(char **map, t_map *mapstr)
{
	int	h;
	int	w;

	mapstr->player = 0;
	mapstr->collect = 0;
	mapstr->exit = 0;
	w = 0;
	while(w < mapstr->w)
	{
		h = 0;
		while(h < mapstr->h)
		{
			if(map[h][w] == 'P')
				 mapstr->player++;
			if(map[h][w] == 'C')
				mapstr->collect++;
			if(map[h][w] == 'E')
				mapstr->exit++;
			h++;
		}
		w++;
	}
	if(mapstr->exit != 1 || !mapstr->collect || mapstr->player != 1)
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

int	check_errors(char **map, t_map *mapstr, t_win *win)
{
	int i;
	int j;
	
	if(!map)
		return (0);
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	if(map_size(map, mapstr) && check_walls(*win)
		&& check_components(map, mapstr))
		return (1);
	return (0);
}	