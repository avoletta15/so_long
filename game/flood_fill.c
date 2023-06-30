#include "so_long.h"

void	flood_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'F';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'F' && map[y][x + 1])
		flood_fill(map, x + 1, y, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'F' && map[y][x - 1])
		flood_fill(map, x - 1, y, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'F' && map[y + 1][x])
		flood_fill(map, x, y + 1, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'F' && map[y - 1][x])
		flood_fill(map, x, y - 1, counter);
}

int	handle_flood_fill(t_win *win)
{
	int		counter;
	char	**backup;
	int		i;

	backup = malloc(sizeof(char *) * (win->mapstr->h + 1));
	if (!backup)
		return (0);
	counter = 0;
	i = -1;
	while (win->map[++i])
		backup[i] = ft_strdup(win->map[i]);
	backup[i] = NULL;
	flood_fill(backup, win->player_x, win->player_y, &counter);
	free_map(backup);
	if (counter == (win->mapstr->exit + win->mapstr->collect))
		return (0);
	else
		return (1);
	return (0);
}
