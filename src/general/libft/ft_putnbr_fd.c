/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:38:39 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 13:38:40 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	new;

	if (n < 0)
	{
		new = -n;
		ft_putchar_fd('-', fd);
	}
	else
		new = n;
	if (new >= 10)
	{
		ft_putnbr_fd(new / 10, fd);
		ft_putchar_fd(new % 10 + '0', fd);
	}
	else
		ft_putchar_fd(new + '0', fd);
}
