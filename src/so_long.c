/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:13:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 12:13:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(t_data *data)
{
	int	i;

	i = ft_strlen(data->ber);
	if (data->ber[i - 1] != 'r' || data->ber[i - 2] != 'e'
		|| data->ber[i - 3] != 'b' || data->ber[i - 4] != '.')
	{
		ft_printf("¡ERROR! .ber format is required for the map");
		exit(0);
	}
}
void	ft_init(t_data *data)
{
	ft_check_map(data);
	data->y = 0;
	data->x = 0;
	data->c = 0;
	data->step = 0;
	data->i = 0;
	data->player = 0;
	data->exit = 0;
	ft_count_p(data);
}

void	init_data(t_data *data)
{
	int	width;
	int	height;

	check_ber(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_error("¡ERROR! Failed to initialize MLX", data);
	data->win = mlx_new_window(data->mlx, data->width * TILE_SIZE,
			data->height * TILE_SIZE, "So Long");
	if (!data->win)
		ft_error("¡ERROR! Could not create window", data);
	data->images = malloc(sizeof(t_image));
	data->images->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &width, &height);
	data->images->empty = mlx_xpm_file_to_image(data->mlx,
			EMPTY, &width, &height);
	data->images->wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &width, &height);
	data->images->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT, &width, &height);
	data->images->collectible = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE, &width, &height);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("¡ERROR! The program needs two arguments");
		return (1);
	}
	data.ber = argv[1];
	check_ber(&data);
	ft_load_map(&data);
	ft_init(&data);
	init_data(&data);
	ft_count_coll(&data);
	ft_check_player(&data);
	ft_draw_map(&data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, on_destroy, &data);
	mlx_hook(data.win, 2, 1L >> 0, key_press, &data);
	mlx_loop(data.mlx);
	return (0);
}
