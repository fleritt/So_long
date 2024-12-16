/* ************************************************************************** */
/*                                                                            */
/*           <                                     :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:14:51 by marvin            #+#    #+#             */
/*   Updated: 2024/11/06 12:14:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 32
# define WIDTH 600
# define HEIGHT 400

# define PLAYER "./tools/sprites/player.xpm"
# define EXIT "./tools/sprites/exit.xpm"
# define WALL "./tools/sprites/wall.xpm"
# define EMPTY "./tools/sprites/empty.xpm"
# define COLLECTIBLE "./tools/sprites/collectible.xpm"

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
//<>

typedef struct s_image
{
    void *player;
    void *wall;
    void *empty;
    void *collectible;
    void *exit;
} t_image;

typedef struct s_data 
{
    void *mlx;
    void *win;
    int height;
    int width;
    int x;
    int y;
    int i;
    int step;
    int c;
    char **map;
    char *ber;
    t_image *images;
} t_data;

int on_destroy(t_data *data);
int key_press(int key, t_data *data);
void ft_load_map(t_data *data);
void ft_error(char *error, t_data *data);
void ft_draw_map(t_data *data);

#endif
