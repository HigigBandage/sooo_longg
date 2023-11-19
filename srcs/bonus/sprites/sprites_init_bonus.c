/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/11/19 16:52:06 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_sprites(t_mlx *mlx)
{
	mlx->img.mat[0] = mlx_xpm_file_to_image(mlx->mlx_ptr, FLOOR_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[1] = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[2] = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLECTIBLE_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[3] = mlx_xpm_file_to_image(mlx->mlx_ptr, EXIT_CLOSED_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[4] = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_DOWN_PATH,
			&mlx->img.w, &mlx->img.h);
	mlx->img.mat[5] = mlx_xpm_file_to_image(mlx->mlx_ptr, ENEMY_PATH,
			&mlx->img.w, &mlx->img.h);
}
