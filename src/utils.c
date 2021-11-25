/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:39:07 by prafael-          #+#    #+#             */
/*   Updated: 2021/11/25 01:56:34 by marvin           ###   ########.fr       */
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

int ft_verify_objects(char *line, char obeject)
{
	int a;

	a = 0;
	if (line != NULL)
	{
		if (ft_strchr(line, obeject))
			a++;
		return(a);
	}
	return(a);
}

void init_struct(t_objects *objects)
{
	objects->C = 0;
	objects->P = 0;
	objects->E = 0;
}