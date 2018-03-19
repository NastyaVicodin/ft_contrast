/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:03:39 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/03 15:28:54 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_lst			*list_read;
	t_contrast		*main_x;

	if (input_param(argc, argv) != 1)
		return (-1);
	list_read = ft_read(argv);
	if (list_read->len == 0)
	{
		printf("Error file\n");
		return (0);
	}
	main_x = (t_contrast*)malloc(sizeof(t_contrast));
	init(main_x, argv);
	main_x = valid_filling(main_x, list_read);
	if (main_x->size_map == 0)
	{
		printf("Error file\n");
		return (0);
	}
	change_mapping(main_x);
	save_file(main_x);
}
