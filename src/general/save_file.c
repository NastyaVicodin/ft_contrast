/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:46:54 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 19:29:56 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void		save_two(t_contrast *main, int fd)
{
	ft_putstr_fd("P2\n", fd);
	ft_putstr_fd("# ", fd);
	ft_putstr_fd(main->name_new_file, fd);
	ft_putstr_fd("\n", fd);
	ft_putnbr_fd(main->lenght, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(main->height, fd);
	ft_putstr_fd("\n", fd);
	ft_putnbr_fd(main->max_grey_lvl, fd);
	ft_putstr_fd("\n", fd);
}

void		save_file(t_contrast *main)
{
	int		x;
	int		y;
	int		i;
	int		fd;

	i = 0;
	y = 0;
	fd = open(main->name_new_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	save_two(main, fd);
	while (y < main->height)
	{
		x = 0;
		while (x < main->lenght)
		{
			if (x != 0)
				ft_putchar_fd(' ', fd);
			ft_putnbr_fd(main->mapping_pixel[i], fd);
			i++;
			x++;
		}
		ft_putchar_fd('\n', fd);
		y++;
	}
	close(fd);
}
