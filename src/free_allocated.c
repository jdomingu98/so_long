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
	ft_putendl_fd("Error", 2);
	if (error_number == 0)
		ft_putendl_fd("Memory was not allocated.", 2);
	else if (error_number == 1)
		ft_putendl_fd("Invalid file descriptor.", 2);
	else if (error_number == 2)
		ft_putendl_fd("Map is not rectangular.", 2);
	else if (error_number == 3)
		ft_putendl_fd("The map is not surrounded by walls.", 2);
	else if (error_number == 4)
		ft_putendl_fd("An unknown character has been read.", 2);
	else if (error_number == 5)
	{
		ft_putstr_fd("There is more than one player ", 2);
		ft_putstr_fd("or exit, ", 2);
		ft_putendl_fd("or there are no collectibles.", 2);
	}
	else if (error_number == 6)
	{
		ft_putstr_fd("Is impossible to get a collectable ", 2);
		ft_putendl_fd("or to reach the exit", 2);
	}
	else if (error_number == 7)
		ft_putendl_fd("There are no players", 2);
}

void	ft_free_data(t_data *data, int error_number)
{
	free(data);
	ft_print_error(error_number);
	exit(EXIT_FAILURE);
}

void	ft_free_map_data(t_data *data, int error_number)
{
	if (data->map_copy)
		free(data->map_copy);
	free(data->map);
	ft_free_data(data, error_number);
}

void	free_map_and_close(t_data *data, int fd, char *line, int error_number)
{
	close(fd);
	free(line);
	if (data->map)
		ft_free_map_data(data, error_number);
	else
		ft_free_data(data, error_number);
}

void	ft_free_all(t_data *data)
{
	ft_delete_images(data);
	mlx_terminate(data->mlx);
	free(data->map);
	free(data);
}
