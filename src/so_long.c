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

void check_ber(t_data *data)
{
    int i;

    i = ft_strlen(data->ber);
    if (data->ber[i - 1] != 'r' || data->ber[i - 2] != 'e' || data->ber[i - 3] != 'b'
		|| data->ber[i - 4] != '.')
	{
       	mlx_destroy_window(data->mlx, data->win);
	   	mlx_destroy_display(data->mlx);
	   	free(data->mlx);
		ft_printf("¡ERROR! El mapa tiene que ser formato .ber");
		exit(0);
	}
}

void init_data(t_data *data)
{
    int width;
    int height;

	check_ber(data);
    data->mlx = mlx_init();
    if (!data->mlx)
        ft_error("¡ERROR! No se pudo inicializar MLX", data);

    data->win = mlx_new_window(data->mlx, data->width * TILE_SIZE, data->height * TILE_SIZE, "So Long");
    if (!data->win)
        ft_error("¡ERROR! No se pudo crear la ventana", data);
    data->images = malloc(sizeof(t_image));
    data->y = 0;
    data->x = 0;
    data->c = 0;
    data->images->player = mlx_xpm_file_to_image(data->mlx, PLAYER, &width, &height);
    data->images->empty = mlx_xpm_file_to_image(data->mlx, EMPTY, &width, &height);
    data->images->wall = mlx_xpm_file_to_image(data->mlx, WALL, &width, &height);
    data->images->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &width, &height);
    data->images->collectible = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE, &width, &height);

}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        t_data	data;

        data.ber = argv[1];
		ft_load_map(&data);
        init_data(&data);
        ft_draw_map(&data);
        
        mlx_hook(data.win, DestroyNotify, StructureNotifyMask, on_destroy, &data);
        mlx_key_hook(data.win, key_press, &data);
        mlx_loop(data.mlx);
        return (0);
    }

    else
    {
        ft_printf("¡ERROR! Se necesitan 2 argumentos");
        return (1);
    }
}