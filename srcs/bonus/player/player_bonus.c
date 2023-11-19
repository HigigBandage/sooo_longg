/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:48:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/11/19 16:52:00 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_to_new_pos(t_mlx *mlx, int new_posx, int new_posy)
{
	int		posx;
	int		posy;

	posx = mlx->player.x;
	posy = mlx->player.y;
	if (mlx->map[posy][posx] == '0' || mlx->map[posy][posx] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[0],
			posx * SPRITES_SIZE, posy * SPRITES_SIZE);
	else if (mlx->map[posy][posx] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[3],
			posx * SPRITES_SIZE, posy * SPRITES_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.mat[4],
		new_posx * SPRITES_SIZE, new_posy * SPRITES_SIZE);
	mlx->player.y = new_posy;
	mlx->player.x = new_posx;
}

static void	check_next_pos(t_mlx *mlx, int new_posx, int new_posy)
{
	if (mlx->map[new_posy][new_posx] == '1')
		move_to_new_pos(mlx, mlx->player.x, mlx->player.y);
	else
	{
		mlx->player.moves++;
		ft_printf("Number of moves : %d\n", mlx->player.moves);
		move_to_new_pos(mlx, new_posx, new_posy);
		if (mlx->map[new_posy][new_posx] == 'C')
		{
			mlx->player.items--;
			if (mlx->player.items == 0)
				set_exit_opened_sprite(mlx);
			mlx->map[new_posy][new_posx] = '0';
		}
		else if (mlx->map[new_posy][new_posx] == 'E')
		{
			if (mlx->player.items == 0)
				exit_game(mlx, "You have won!");
			else
				ft_printf("There are still %d items!\n", mlx->player.items);
		}
		else if (mlx->map[new_posy][new_posx] == 'M')
			exit_game(mlx, "GAME OVER! You are dead!");
	}
}

void	move_player(int key, t_mlx *mlx)
{
	if (key == UP)
	{
		mlx->img.mat[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_UP_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x, mlx->player.y - 1);
	}
	else if (key == DOWN)
	{
		mlx->img.mat[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_DOWN_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x, mlx->player.y + 1);
	}
	else if (key == LEFT)
	{
		mlx->img.mat[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_LEFT_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x - 1, mlx->player.y);
	}
	else if (key == RIGHT)
	{
		mlx->img.mat[4] = mlx_xpm_file_to_image(mlx->mlx_ptr,
				PLAYER_RIGHT_PATH, &mlx->img.w, &mlx->img.h);
		check_next_pos(mlx, mlx->player.x + 1, mlx->player.y);
	}
}
