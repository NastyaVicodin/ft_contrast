/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_change_mapping.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:31:53 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/04 18:34:19 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	thread_change_mapping(t_contrast *main_x)
{
	pthread_t	*handle;
	t_thread	*tmp;
	int			res;
	int			cores;
	int			i;

	i = -1;
	cores = (int)sysconf(_SC_NPROCESSORS_ONLN);
	tmp = (t_thread*)malloc(sizeof(t_thread) * (cores + 1));
	handle = (pthread_t*)malloc(sizeof(pthread_t) * cores);
	while (++i < cores)
	{
		tmp[i].thread = ft_copy(main_x, sizeof(t_contrast) + 1);
		tmp[i].thread->count = i;
		tmp[i].thread->array = get_borders(main_x);
		res = pthread_create(&handle[i], 0, thread_change, tmp[i].thread);
		((res != 0) ? printf("ERROR %d\n", res) : 0);
		if (res != 0)
			return ;
	}
	free(main_x);
	i = -1;
	while (++i < cores)
		pthread_join(handle[i], 0);
	thread_save_file(tmp);
}
