/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_victory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:32:50 by marvin            #+#    #+#             */
/*   Updated: 2024/12/16 20:32:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_coll(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x] == 'C')
				data->c++;
			x++;
		}
		y++;
	}
}

void	ft_victory(t_data *data)
{
	ft_printf("Movements: %d\n", data->step);
	ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	if (data->map)
		destroy_map(data);
	mlx_destroy_image(data->mlx, data->images->player);
	mlx_destroy_image(data->mlx, data->images->empty);
	mlx_destroy_image(data->mlx, data->images->wall);
	mlx_destroy_image(data->mlx, data->images->exit);
	mlx_destroy_image(data->mlx, data->images->collectible);
	free(data->images);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}