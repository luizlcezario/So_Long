/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:53 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/24 23:13:15 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*img_initalize(char *img, void *mlx, t_sprite *sprite)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image
		(mlx, img, &sprite->img_width, &sprite->img_height);
	return (img_ptr);
}

int	load_sprites(t_vars *vars, t_sprite *sprite)
{
	sprite->wall = img_initalize(WALL, vars->mlx, sprite);
	sprite->ground = img_initalize(GROUND, vars->mlx, sprite);
	sprite->collect = img_initalize(COLLECT, vars->mlx, sprite);
	sprite->exit = img_initalize(EXIT, vars->mlx, sprite);
	sprite->player = ft_calloc(5, sizeof(void *));
	sprite->enemies = ft_calloc(5, sizeof(void *));
	if (sprite->player == NULL || sprite->enemies == NULL)
		return (error(14, "Alocation of memory error in module.map!"));
	sprite->player[0] = img_initalize(PLAYER_1, vars->mlx, sprite);
	sprite->player[1] = img_initalize(PLAYER_2, vars->mlx, sprite);
	sprite->player[2] = img_initalize(PLAYER_3, vars->mlx, sprite);
	sprite->player[3] = img_initalize(PLAYER_4, vars->mlx, sprite);
	sprite->enemies[0] = img_initalize(ENEMY_1, vars->mlx, sprite);
	sprite->enemies[1] = img_initalize(ENEMY_2, vars->mlx, sprite);
	sprite->enemies[2] = img_initalize(ENEMY_3, vars->mlx, sprite);
	sprite->enemies[3] = img_initalize(ENEMY_4, vars->mlx, sprite);
	return (0);
}

int	start_game(t_module *module)
{
	module->vars = malloc(1 * sizeof(t_vars));
	module->player = malloc(1 * sizeof(t_player));
	module->coin = malloc(1 * sizeof(t_coin));
	module->sprite = malloc(6 * sizeof(t_sprite));
	module->end_game = FALSE;
	if (!module->sprite || !module->vars || !module->player || !module->coin)
		return (error(14, "Alocation of memory error in module.map!"));
	module->vars->mlx = mlx_init();
	if (module->vars->mlx == NULL)
		return (error(15, "It is not possible to start the game!"));
	module->vars->win = mlx_new_window(module->vars->mlx,
			module->map->width * SPRITE_SIZE,
			module->map->height * SPRITE_SIZE, "so_long");
	if (module->vars->win == NULL)
		return (error(15,
				"It is not possible to open the window of the game!"));
	if (load_sprites(module->vars, module->sprite) == 1)
		return (1);
	module->player->player_eye = 0;
	module->player->player_step = 0;
	if (print_map(module) == 1)
		return (1);
	return (0);
}
