/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:37:15 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/21 16:20:08 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_module *module, void *sprite)
{
	mlx_put_image_to_window (module->vars->mlx, module->vars->win, sprite,
		SPRITE_SIZE * module->map->col,
		SPRITE_SIZE * module->map->row);
}

static void	position_player(t_module *module)
{
	put_img(module, module->sprite->player[module->player->player_eye]);
	module->player->player_x = module->map->col;
	module->player->player_y = module->map->row;
}

static void	coin_print(t_module *module)
{
	module->coin->amount = module->coin->amount + 1;
	put_img(module, module->sprite->collect);
}

static void	enemines_print(t_module *module)
{
	int	col;
	int	row;

	col = module->map->col - module->player->player_x;
	row = module->map->row - module->player->player_y;
	if (col < row)
	{
		if(module->map->col <= module->player->player_x)
			put_img(module, module->sprite->enemies[0]);
		else
			put_img(module, module->sprite->enemies[3]);
	}
	else
		if(module->map->col <= module->player->player_x)
			put_img(module, module->sprite->enemies[2]);
		else
			put_img(module, module->sprite->enemies[1]);;
}

static int	choose_sprite(char *line, t_module *module)
{
	if (line[module->map->col] == '0')
		put_img(module, module->sprite->ground);
	else if (line[module->map->col] == '1')
		put_img(module, module->sprite->wall);
	else if (line[module->map->col] == 'C')
		coin_print(module);
	else if (line[module->map->col] == 'E')
		put_img(module, module->sprite->exit);
	else if (line[module->map->col] == 'P')
		position_player(module);
	else if (line[module->map->col] == 'J')
		enemines_print(module);
	else
		return (1);
	return (0);
}

int	print_map(t_module *module)
{
	module->map->row = 0;
	module->coin->amount = 0;
	while (module->map->row < module->map->height)
	{
		module->map->col = 0;
		while (module->map->col < module->map->width)
		{
			if (choose_sprite(module->map->map[module->map->row], module) == 1)
				return (error(0, "It is not possible to find the sprite!"));
			module->map->col++;
		}
		module->map->row++;
	}
	return (0);
}
