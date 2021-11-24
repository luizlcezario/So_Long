/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:44:25 by prafael-          #+#    #+#             */
/*   Updated: 2021/11/21 16:20:09 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// erro map .ber
// sprites personagem
// norminette

int	main(int argc, char **argv)
{
	t_module	*module;

	if (argc == 2)
	{
		module = malloc(1 * sizeof(t_module));
		if(module == NULL)
			exit(error(14, NULL)); 
		if (verify_map(argv[1], module) == 0)
		{
			start_game(module);
			hook(module);
			mlx_loop(module->vars->mlx);
		}
		else
		{
			clear_map(module->map);
			free_ptr((void **)&module);
			exit(-1);
		}
	}
	else
		exit (error(22, NULL));
}
