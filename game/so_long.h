#ifndef SO_LONG_H
#define SO_LONG_H
#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdlib.h>


//MAC KEYS
# define K_ESC					53
# define K_UP					13
# define K_LEFT					0
# define K_RIGHT				2
# define K_DOWN					1
# define A_UP					0x7E
# define A_DOWN					0x7D
# define A_LEFT					0x7B
# define A_RIGHT				0x7C


typedef struct s_img
{
	void	*wall;
	void	*exit_c;
	void	*exit_o;
	void	*player;
	void	*collect;
	void	*back;
}	t_img;

typedef struct s_map
{
	int	h; // 5 (map_size) 
	int	w; // 14 (map_size)
	int	exit;
	int	collect;
	int	player;
}	t_map;

typedef struct s_win
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	char	**map;	
	t_map	*mapstr;
	t_img	*img;
	int		moves;
	int		over; 
	int 	player_x; // 1 (put_player)
	int		player_y; // 2 (put_player)
}	t_win;

//maps
char	**read_map(char *arg);
void	free_map(char **map );
int		map_size(t_win win);

//flood-fill
void	flood_fill(char **map, int x, int y, int *counter);
int		handle_flood_fill(t_win *win);

//errors
int		check_errors(t_win *win);
int		check_walls(t_win win);
int		check_file_type(char *file);
int		check_components(t_win *win);
void	map_error(t_win *win);
int		coordenada (t_win *win);

//components
void	game_window(t_win *win);
void	create_img(t_win *win);
void	put_img(t_win *win, void *img, int x, int y);

//design
void	draw_img(t_win *win);
void	create_exit(t_win *win, int x, int y);
void	put_player(t_win *win, int x, int y);

//hooks
int	exit_game(t_win *win);

int	read_esc(int keycode, t_win *win);
int	key_hooks(int keycode, t_win *win);

//play
void	move_up(t_win *win);
void	move_down(t_win *win);
void	move_left(t_win *win);
void	move_right(t_win *win);

#endif
