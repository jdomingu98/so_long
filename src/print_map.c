/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:51:33 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/04 18:51:35 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap_and_free(t_data *data, char *line)
{
	char	*aux;

	aux = ft_strdup(data->map);
	free(data->map);
	data->map = ft_strjoin(aux, line);
	free(aux);
	free(line);
}

int	check_exit(t_data *data, char next_position)
{
	if (next_position == 'E' && data->nbr_collect != 0)
	{
		ft_putendl_fd("There are some collectables left!!", 1);
		return (1);
	}
	else if (next_position == 'E' && data->nbr_collect == 0)
	{
		ft_putendl_fd("Congrats, you won!!", 1);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_print_map(t_data *data, int img_size)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (data->map[++i])
	{
		x = (i / data->map_width) * img_size;
		y = (i % data->map_width) * img_size;
		if (data->map[i] != '\n')
			mlx_image_to_window(data->mlx, data->bg_img, y, x);
		if (data->map[i] == '1')
			mlx_image_to_window(data->mlx, data->wall_img, y, x);
		else if (data->map[i] == 'C')
			mlx_image_to_window(data->mlx, data->collect_img, y, x);
		else if (data->map[i] == 'E')
			mlx_image_to_window(data->mlx, data->exit_img, y, x);
		else if (data->map[i] == 'P')
			mlx_image_to_window(data->mlx, data->player_img, y, x);
	}
}
