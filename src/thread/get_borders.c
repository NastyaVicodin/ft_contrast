/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_borders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 21:17:53 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/04 18:31:38 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

static int	*calc_borders(int *arr_coord, int pixels, int cores, int parts)
{
	int		i;
	int		mod;
	int		*arr_borders;
	int		res;

	i = -1;
	res = 0;
	arr_borders = (int *)malloc(sizeof(int) * parts);
	while (++i < parts)
		arr_borders[i] = parts;
	mod = pixels % cores;
	i = 0;
	while (mod--)
		arr_borders[i++]++;
	i = -1;
	while (++i < parts)
	{
		arr_coord[i] = res;
		res += arr_borders[i];
	}
	arr_coord[i] = res;
	return (arr_coord);
}

int			*get_borders(t_contrast *main_list)
{
	int		cores;
	int		*arr_coord;
	int		pixels;
	int		parts;

	cores = (int)sysconf(_SC_NPROCESSORS_ONLN);
	pixels = main_list->size_map;
	parts = pixels / cores;
	arr_coord = (int *)malloc(sizeof(int) * (parts + 1));
	arr_coord = calc_borders(arr_coord, pixels, cores, parts);
	return (arr_coord);
}
