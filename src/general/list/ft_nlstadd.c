/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:08:00 by asvirido          #+#    #+#             */
/*   Updated: 2018/02/02 20:08:02 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../general.h"

void	ft_nlstadd(t_lst *nlst, char *string)
{
	while (nlst->next)
		nlst = nlst->next;
	nlst->next = ft_nlstnew(string);
}
