/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_contrast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:42:50 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 19:31:26 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	algo_contrast(t_contrast *main, int i)
{
	int		res;

	res = main->mapping_pixel[i];
	res = res * main->contrast_lvl / 100;
	main->mapping_pixel[i] = res;
}
