/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:27:39 by marvin            #+#    #+#             */
/*   Updated: 2024/12/09 20:27:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int on_destroy(t_data *data)
{
	int i;

	i = 0;
	while (i < data->height)
	{
		free(data->map[i]);
		i++;
	}
    free(data->map);
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
    return (0);
}

void ft_error(char *error, t_data *data)
{
	ft_printf(error);
	on_destroy(data);
}