/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_mapping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:42:44 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 19:32:21 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	change_mapping(t_contrast *main)
{
	int		i;

	i = 0;
	while (i < main->size_map)
	{
		algo_contrast(main, i);
		i++;
	}
}
