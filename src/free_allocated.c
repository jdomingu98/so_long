/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:26:23 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/06 22:26:26 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(int error_number)
{
	ft_putstr_fd("Error: ", 1);
	(void) error_number;
}

void	ft_free_data(t_data *data)
{
	free(data);
	exit(EXIT_FAILURE);
}

void	ft_free_map_data(t_data *data)
{
	free(data->map);
	ft_free_data(data);
}

void	ft_free_map_and_close(t_data *data, int fd)
{
	close(fd);
	if (data->map)
		ft_free_map_data(data);
	else
		ft_free_data(data);
}

void	ft_free_all(t_data *data)
{
	ft_delete_images(data);
	mlx_terminate(data->mlx);
	free(data->map);
	free(data);
}
