/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:33:47 by marvin            #+#    #+#             */
/*   Updated: 2024/11/10 13:33:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_w(t_data *data)
{
    if (data->map[data->y - 1][data->x] != '1')
	{
		if(data->map[data->y - 1][data->x] == 'C' || 
			data->map[data->y - 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->y--;
			data->map[data->y][data->x] = 'P';
			data->step++;
			ft_draw_map(data);
		}
	}
}

void move_a(t_data *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if(data->map[data->y][data->x - 1] == 'C' || 
			data->map[data->y][data->x - 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->x--;
			data->map[data->y][data->x] = 'P';
			data->step++;
			ft_draw_map(data);
		}
	}
}

void move_s(t_data *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if(data->map[data->y + 1][data->x] == 'C' || 
			data->map[data->y + 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->y++;
			data->map[data->y][data->x] = 'P';
			data->step++;
			ft_draw_map(data);
		}
	}
}

void move_d(t_data *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if(data->map[data->y][data->x + 1] == 'C' || 
			data->map[data->y][data->x + 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->x++;
			data->map[data->y][data->x] = 'P';
			data->step++;
			ft_draw_map(data);
		}
	}
}

int key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		on_destroy(data);
    if (key == XK_w || key == XK_Up)
	{
        move_w(data);
	}
    if (key == XK_a || key == XK_Left)
	{
        move_a(data);
	}
    if (key == XK_s || key == XK_Down)
	{
        move_s(data);
	}
    if (key == XK_d || key == XK_Right)
	{
        move_d(data);
	}
	return (0);
}
