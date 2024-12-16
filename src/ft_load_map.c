/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:41:09 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 13:41:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_valid_char(char *line, int f)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E' && line[i] != '\n'
			&& line[i] != 'C' && line[i] != 'P' && line[i] != '\r')
			return (0);
		i++;
	}
	if (f == 1)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] != '1' && line[i] != '\r' && line[i] != '\n')
				return (0);
			i++;
		}
	}
	else
		if (line[0] != '1' || line[i - 3] != '1')
			return (0);
	return (1);
}

void ft_valid_map(t_data *data)
{
	int fd;
	char *line;
	int f;
	int valid;

	fd = open(data->ber, O_RDONLY);
	if(fd == -1)
		ft_error("¡ERROR! El archivo no existe", data);
	f = 1;
	line = get_next_line(fd);
	if (!line)
		ft_error("¡ERROR! El archivo no es válido", data);
	while (line)
	{
		valid = ft_valid_char(line, f);
		if (valid == 0)
		{
			free(line);
			ft_error("¡ERROR! El Mapa no es válido", data);
		}
		f = 0;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void ft_count_map_size(t_data *data)
{
    int fd;
    char *line;

	data->width = 0;
    data->height = 0;
    fd = open(data->ber, O_RDONLY);
    if (fd == -1)
		ft_error("¡ERROR! El archivo no existe", data);
    line = get_next_line(fd);
    if (!line)
		ft_error("¡ERROR! El archivo no es válido", data);
    data->width = ft_strlen(line) - 1;
    while (line)
    {
        data->height++;
		free(line);
        line = get_next_line(fd);
    }
	free(line);
    close(fd);
}

void ft_load_map(t_data *data)
{
	int fd;
	char *line;
	int i;

	i = 0;
	ft_valid_map(data);
	ft_count_map_size(data);
	fd = open(data->ber, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		ft_error("¡ERROR!", data);
	while (i < data->height)
	{
		line = get_next_line(fd);
		if(!line)
			ft_error("¡ERROR!", data);
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_error("¡ERROR!", data);
		data->map[i][data->width - 1] = '\0';
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}