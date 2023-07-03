/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:33:54 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:34:22 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *arg)
{
	char	**map;
	char	*line;
	char	*temp;
	char	*sketch;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (NULL);
	sketch = malloc(sizeof(char));
	sketch[0] = '\0';
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = sketch;
		sketch = ft_strjoin(sketch, line);
		free(line);
		free(temp);
	}
	map = ft_split(sketch, '\n');
	free(sketch);
	close(fd);
	return (map);
}

int	map_size(t_win win)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (win.map[h])
	{
		w = 0;
		while (win.map[h][w])
			w++;
		h++;
	}
	if (h < 3 || (h && h == w))
		return (0);
	win.mapstr->h = h;
	win.mapstr->w = w;
	return (1);
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
