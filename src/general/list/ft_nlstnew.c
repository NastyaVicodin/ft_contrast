/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:06 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/02 20:08:07 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

t_lst		*ft_nlstnew(char *string)
{
	t_lst	*nw;

	nw = (t_lst *)malloc(sizeof(t_lst));
	if (nw)
	{
		nw->line = ft_strdup(string);
		nw->len = ft_strlen(string);
		nw->next = NULL;
		return (nw);
	}
	else
		return (NULL);
}
