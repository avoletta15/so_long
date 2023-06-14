#include "so_long.h"
#include "../mlx/mlx.h"

char	**read_map(char *arg) //the argument of this function is the map file we choose to play in
{
	char	**map;
	char	*line;
	char	*temp;
	char 	*sketch;
	int		fd;

	fd = open(arg, O_RDONLY); // fd generated when we open the map file to read it
	if (fd < 0)
		return(NULL);
	sketch = malloc(sizeof(char));
	sketch[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		temp = sketch;
		sketch = ft_strjoin(sketch, line);
		free(line);
		free(temp);
	}
	map = ft_split(sketch, '\n');
	free(sketch);
	close(fd);
	return(map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
