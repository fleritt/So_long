/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:11:18 by marvin            #+#    #+#             */
/*   Updated: 2025/01/11 10:11:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_map(t_data *data)
{
    int x;
    int y;

    y = data->height;
	x = 0;
	while(x < data->width)
	{
		if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != '\n' 
			&& data->map[y - 1][x] != '\0')
			ft_player_invalid("The map is not valid", data);
		x++;
	}
}
void ft_count_p(t_data *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (data->map[y][x] == 'P')
				data->player++;
			if (data->map[y][x] == 'E')
				data->exit++;
			x++;
		}
		y++;
	}
}
void	ft_check_player(t_data *data)
{
	if (data->player != 1)
		ft_error("ERROR!! There can only be one character", data);
	if (data->exit != 1)
		ft_error("ERROR!! There can only be one exit", data);
	if (data->c < 1)
		ft_error("ERROR!! At least one collectible is needed", data);
}
