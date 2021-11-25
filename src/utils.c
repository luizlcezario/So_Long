/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:39:07 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/24 23:30:34 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verify_str(char *str, char *ver, int max_search)
{
	int	a;

	a = 0;
	if (str == NULL || ver == NULL)
		return (1);
	while (*str != 0 && a <= max_search && ft_strchr(ver, *str))
	{
		str++;
		a++;
	}
	if (a == max_search)
		return (0);
	return (1);
}

void	free_ptr(void **ptr)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_verify_objects(char *line, char obeject)
{
	int	a;

	a = 0;
	if (line != NULL)
	{
		if (ft_strchr(line, obeject))
			a++;
		return (a);
	}
	return (a);
}

void	init_struct(t_objects *objects)
{
	objects->c = 0;
	objects->p = 0;
	objects->e = 0;
}
