/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:41:03 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/02 20:10:04 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	mlx_image_t	*bg_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*exit_img;
	char		*map;
	char		*map_copy;
	int			map_height;
	int			map_width;
	int			player_pos;
	int			nbr_collect;
	int			nbr_players;
	int			nbr_exits;
	int			player_moves;
}	t_data;

void	ft_check_map(t_data *data, char *name);
void	init_sprites(t_data *data);
void	ft_delete_images(t_data *data);
void	ft_print_map(t_data *data, int img_size);
void	press_key(mlx_key_data_t keydata, void *data);
int		check_exit(t_data *data, char next_position);
void	free_map_and_close(t_data *data, int fd, char *line, int error_number);
void	ft_free_data(t_data *data, int error_number);
void	ft_free_map_data(t_data *data, int error_number);
void	ft_free_all(t_data *data);
void	ft_swap_and_free(t_data *data, char *line);
void	ft_print_error(int error_number);
int		path_finding(t_data *data, int player_pos, int objetive, char object);
void	set_player_position_and_map_copy(t_data *data);
void	check_path(t_data *data, int pos, char object);

#endif
