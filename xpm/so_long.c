#include "so_long.h"
#include "../mlx/mlx.h"


int	main(int ac, char **arg)
{
	t_win win;

	if(ac == 2 && check_file_type(arg[1]))
	{
		win.map = read_map(arg[1]);
		win.mapstr = malloc(sizeof(t_map));
		win.img = malloc(sizeof(t_img));
		if(check_errors(&win))
		{
			game_window(&win);
			mlx_hook(win.win_ptr, 17, 0, exit_game, &win);
			mlx_key_hook(win.win_ptr, read_esc, &win);
			mlx_hook(win.win_ptr, 02, (1L << 0), key_hooks, &win);
			mlx_loop(win.mlx_ptr);
		}

	}
	else
	{
		ft_printf("\e[0;31mINVALID MAP FILE\n");
		exit(1);
	}
	return 0;
}



// 1 function