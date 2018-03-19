/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:33:24 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/04 18:33:25 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

int		main(int argc, char **argv)
{
	t_lst			*list_read;
	t_contrast		*main_x;

	if (input_param(argc, argv) != 1)
		return (-1);
	list_read = ft_read_thread(argv);
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
	thread_change_mapping(main_x);
}
