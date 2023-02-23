/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:33:00 by jdomingu          #+#    #+#             */
/*   Updated: 2023/02/07 21:32:00 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_if_move_pos(t_data *data, int *moves, int i, char object)
{
	return (data->map_copy[moves[i]] != '1' && (object == 'E'
			|| (object == 'C'
				&& data->map_copy[moves[i]] != 'E')));
}

static int	*init_moves(t_data *data, int player_pos)
{
	int	*moves;

	moves = (int *) malloc(4 * sizeof(int));
	moves[0] = player_pos - data->map_width;
	moves[1] = player_pos + 1;
	moves[2] = player_pos + data->map_width;
	moves[3] = player_pos - 1;
	return (moves);
}

void	check_path(t_data *data, int pos, char object)
{
	if (!path_finding(data, data->player_pos, pos, object))
		ft_free_map_data(data, 6);
	free(data->map_copy);
	data->map_copy = ft_strdup(data->map);
}

int	path_finding(t_data *data, int player_pos, int objetive, char object)
{
	int	i;
	int	*moves;

	moves = init_moves(data, player_pos);
	i = -1;
	if (player_pos == objetive)
	{
		free(moves);
		return (1);
	}
	while (++i < 4)
	{
		if (check_if_move_pos(data, moves, i, object))
		{
			data->map_copy[player_pos] = '1';
			if (path_finding(data, moves[i], objetive, object))
			{
				free(moves);
				return (1);
			}
		}
	}
	free(moves);
	return (0);
}

void	set_player_position_and_map_copy(t_data *data)
{
	size_t	i;

	i = 0;
	data->map_copy = ft_strdup(data->map);
	while (data->map[i] && data->map[i] != 'P')
		i++;
	if (i == ft_strlen(data->map))
		ft_free_map_data(data, 7);
	data->player_pos = i;
}
