/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:44:49 by marvin            #+#    #+#             */
/*   Updated: 2024/12/14 15:44:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_position(t_data *data, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, data->images->player,
		x * TILE_SIZE, y * TILE_SIZE);
	data->x = x;
	data->y = y;
}

void ft_exit_coll(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->exit,
			x * TILE_SIZE, y * TILE_SIZE);
	}
	if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->images->collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	}
}

void ft_draw_map(t_data *data)
{
    int x;
	int y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->images->wall,
				x * TILE_SIZE, y * TILE_SIZE);
            else if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->images->empty,
				x * TILE_SIZE, y * TILE_SIZE);
            else if (data->map[y][x] == 'C')
                ft_exit_coll(data, x, y);
            else if (data->map[y][x] == 'E')
                ft_exit_coll(data, x, y);
            else if (data->map[y][x] == 'P')
				ft_position(data, x, y);
            x++;
        }
        y++;
    }
}
