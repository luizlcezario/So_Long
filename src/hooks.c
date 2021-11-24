/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:39 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/21 16:20:10 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_hook(int keycode, t_module *module)
{
	if (keycode == 113 || keycode == KEY_ESC)
		close_all(module);
	else if (module->end_game == TRUE)
		return (0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(module, module->player->player_x + 1, module->player->player_y, 2);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move(module, module->player->player_x - 1, module->player->player_y, 1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move(module, module->player->player_x, module->player->player_y + 1, 0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move(module, module->player->player_x, module->player->player_y - 1, 3);
	return (0);
}

static int	print_steps(t_module *module)
{
	char	*test;

	test = ft_formatf("STEPS: %d", module->player->player_step);
	mlx_string_put(module->vars->mlx, module->vars->win, 11, 11,
		0x00FFFFFF, test);
	free_ptr((void **)&test);
	return (0);
}

static int	resume_game(t_module *module)
{
	module->player->player_eye = 0;
	print_map(module);
	return (0);
}

void	hook(t_module *module)
{
	mlx_key_hook(module->vars->win, &key_hook, module);
	mlx_loop_hook(module->vars->mlx,&print_steps, module);
	mlx_hook(module->vars->win, 17, 0, &close_all, module);
	mlx_hook(module->vars->win, 9, 1L<<21, &resume_game, module);
}
	/* mlx_hook(module->vars->win, 45, 0 , &move_eneminies, module); */
