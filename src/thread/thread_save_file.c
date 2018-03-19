/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_save_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:32:41 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/04 18:37:26 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

static int		get_color(t_thread *tmp, int i, int cores)
{
	int		res;
	int		j;

	j = 0;
	res = -1;
	while (j < cores)
	{
		if (i < tmp[j].thread->array[tmp[j].thread->count + 1])
			return (tmp[j].thread->mapping_pixel[i]);
		j++;
	}
	return (res);
}

void			thread_save_file(t_thread *tmp)
{
	int		x;
	int		y;
	int		i;
	int		fd;
	int		color;

	i = 0;
	y = -1;
	fd = open(tmp[i].thread->FILE, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	tmp[0].cores = (int)sysconf(_SC_NPROCESSORS_ONLN);
	save_two(tmp[i].thread, fd);
	while (++y < tmp[0].thread->height)
	{
		x = -1;
		while (++x < tmp[0].thread->lenght)
		{
			((x != 0) ? write(fd, " ", 1) : 0);
			color = get_color(tmp, i, tmp[0].cores);
			ft_putnbr_fd(color, fd);
			i++;
		}
		write(fd, "\n", 1);
	}
	close(fd);
}
