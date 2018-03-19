/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:42:57 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/03 13:42:58 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	init(t_contrast *main, char **argv)
{
	main->name_new_file = ft_strdup(argv[6]);
	main->contrast_lvl = ft_atoi(argv[4]);
}
