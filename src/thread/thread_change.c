/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:31:45 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/04 18:33:18 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	*thread_change(void *parameter)
{
	int			i;
	t_contrast	*x;

	x = (t_contrast*)parameter;
	i = x->array[x->count];
	while (i < x->array[x->count + 1])
	{
		algo_contrast(x, i);
		i++;
	}
	return (0);
}
