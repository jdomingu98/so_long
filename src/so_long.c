/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:07:09 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/02 20:09:57 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//gcc -Wextra -Wall -Werror src/so_long.c src/check_map.c src/load_sprites.c src/move_player.c src/print_map.c src/free_allocated.c gnl/get_next_line.c gnl/get_next_line_utils.c libft/libft.a MLX42/libmlx42.a -I ./MLX42/include -ldl -lglfw -pthread -lm -D BUFFER_SIZE=42 -o so_long

static void	ft_check_extension(t_data *data, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len > 4 && name[len - 4] == '.' && name[len - 3] == 'b'
		&& name[len - 2] == 'e' && name[len - 1] == 'r')
		return ;
	free(data);
	//print_error
	exit(EXIT_FAILURE);
}

static void	init_data(t_data *data, char *map_name)
{
	data->player_moves = 0;
	ft_check_extension(data, map_name);
	data->map = ft_calloc(1, sizeof(char));
	if (!(data->map))
		ft_free_data(data);
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
			exit(EXIT_FAILURE);
		init_data(data, argv[1]);
		data->mlx = mlx_init(32 * (data->map_width - 1),
				32 * (data->map_height - 1), "so_long", true);
		if (!(data->mlx))
		{
			free(data->map);
			free(data);
			exit(EXIT_FAILURE);
		}
		init_sprites(data);
		ft_print_map(data, 32);
		mlx_key_hook(data->mlx, &press_key, data);
		mlx_loop(data->mlx);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
		ft_putendl_fd("Invalid number of arguments.", 1);
		exit(EXIT_FAILURE);
}
