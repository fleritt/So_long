/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:36:23 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 13:36:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_data *data, int xc, int yc, int radius, int color)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (y >= x)
    {
        my_mlx_pixel_put(data, xc + x, yc + y, color);
        my_mlx_pixel_put(data, xc - x, yc + y, color);
        my_mlx_pixel_put(data, xc + x, yc - y, color);
        my_mlx_pixel_put(data, xc - x, yc - y, color);
        my_mlx_pixel_put(data, xc + y, yc + x, color);
        my_mlx_pixel_put(data, xc - y, yc + x, color);
        my_mlx_pixel_put(data, xc + y, yc - x, color);
        my_mlx_pixel_put(data, xc - y, yc - x, color);
        if (d < 0)
            d = d + 4 * x + 6;
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int	main(void)
{
	t_data	data;
	int x;
	int y;

	x = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello world!");
	data.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
									&data.endian);
	while (x < WIDTH * 0.25)
	{
		y = 0;
		while (y < HEIGHT * 0.25)
		{
			my_mlx_pixel_put(&data, x, y, 0xff0000);
			y++;
		}
		x++;
	}
	draw_circle(&data, WIDTH / 2, HEIGHT / 2, 50, 0xff0000);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img,0, 0);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_key_hook(data.win_ptr, key_press, &data);
	mlx_loop(data.mlx_ptr);
}