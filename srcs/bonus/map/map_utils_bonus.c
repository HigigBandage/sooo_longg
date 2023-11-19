/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/11/19 16:51:54 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

int	get_map_size(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	get_map_height(char **map)
{
	int	size;

	size = get_map_size(map) * SPRITES_SIZE;
	return (size);
}

int	get_map_width(char **map)
{
	int	size;

	size = ft_strlen(map[0]) * SPRITES_SIZE;
	return (size);
}
