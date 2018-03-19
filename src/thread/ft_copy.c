/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:31:26 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/04 18:31:29 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

void	*ft_copy(void *data, size_t size)
{
	void	*shit;

	shit = malloc(size);
	memcpy(shit, data, size);
	return (shit);
}
