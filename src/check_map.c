/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:09:43 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/02 20:09:46 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_inside_wall(t_data *data)
{
	int	i;

	i = -1;
	while (data->map[++i])
	{
		if (data->map[i] == 'C')
			data->nbr_collect++;
		else if (data->map[i] == 'E')
			data->nbr_exits++;
		else if (data->map[i] == 'P')
			data->nbr_players++;
		else if (data->map[i] != '1' && data->map[i] != '0'
			&& data->map[i] != '\n')
			ft_free_map_data(data); //print_error
	}
	if (data->nbr_collect < 1 || data->nbr_exits < 1
		|| data->nbr_players != 1)
		ft_free_map_data(data); //print_error
}

static void	ft_check_vertical_wall(t_data *data, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (data->map[i] == '1')
			i += data->map_width;
		else
			ft_free_map_data(data); //print_error
	}
	i = data->map_width - 2;
	while (i < len)
	{
		if (data->map[i] == '1')
			i += data->map_width;
		else
			ft_free_map_data(data); //print_error
	}
}

static void	ft_check_wall(t_data *data)
{
	int	i;
	int	last_idx;
	int	len;

	i = -1;
	len = ft_strlen(data->map);
	last_idx = len - data->map_width - 1;
	while (++i != data->map_width)
	{
		if (data->map[i] != '1' && data->map[i] != '\n')
			ft_free_map_data(data); //print_error
	}
	while (++last_idx != len)
	{
		if (data->map[i] != '1' && data->map[i] != '\n')
			ft_free_map_data(data); //print_error
	}
	ft_check_vertical_wall(data, len);
}

static void	ft_search_eol(char *line, int *control)
{
	int	i;

	i = -1;
	*control = 1;
	while (line[++i])
	{
		if (line[i] == '\n')
			*control = 0;
	}
}

void	ft_check_map(t_data *data, char *map_name)
{
	char	*line;
	int		fd;
	int		control;

	fd = open(map_name, O_RDONLY); //Comprobar modo bien escrito
	if (fd < 0)
		ft_free_data(data);
	control = 2;
	while (control != 1)
	{
		data->map_height++;
		line = get_next_line(fd);
		if (!line)
			break ;//ft_free_map_and_close(data, fd);
		if (control == 2)
			data->map_width = ft_strlen(line);
		ft_search_eol(line, &control);
		if ((int) ft_strlen(line) + control != data->map_width)
			ft_free_map_and_close(data, fd);
		data->map = ft_strjoin(data->map, line);
		free(line);
	}
	close(fd);
	ft_check_wall(data);
	ft_check_inside_wall(data);
}
