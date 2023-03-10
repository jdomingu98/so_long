/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:07:09 by jdomingu          #+#    #+#             */
/*   Updated: 2023/02/20 21:15:34 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_extension(t_data *data, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len > 4 && name[len - 4] == '.' && name[len - 3] == 'b'
		&& name[len - 2] == 'e' && name[len - 1] == 'r')
		return ;
	ft_free_data(data, 0);
}

static void	init_data(t_data *data, char *map_name)
{
	data->player_moves = 0;
	ft_check_extension(data, map_name);
	data->map = ft_calloc(1, sizeof(char));
	if (!(data->map))
		ft_free_data(data, 0);
	ft_check_map(data, map_name);
}

// IMAGES DIMENSIONS: 32x32 px
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
		{
			ft_print_error(0);
			exit(EXIT_FAILURE);
		}
		init_data(data, argv[1]);
		data->mlx = mlx_init(32 * (data->map_width - 1),
				32 * (data->map_height - 1), "so_long", true);
		if (!(data->mlx))
			ft_free_map_data(data, 0);
		init_sprites(data);
		ft_print_map(data, 32);
		mlx_key_hook(data->mlx, &press_key, data);
		mlx_loop(data->mlx);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Invalid number of arguments.", 2);
	exit(EXIT_FAILURE);
}
