/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_filling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:03:39 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/03 10:50:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static char		*ft_strcut(char *str, char c)
{
	int		i;
	int		len;
	char	*tmp;

	if (str)
	{
		i = 0;
		while (str[i] && str[i] != c)
			i++;
		len = i;
		i = 0;
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		tmp = len ? ft_strncpy(tmp, str, len) : ft_strdup("");
		tmp[len] = '\0';
		free(str);
		str = ft_strdup(tmp);
		free(tmp);
		return (str);
	}
	return (NULL);
}

static	t_lst	*cut_sharps(t_lst *list_read)
{
	t_lst	*head;
	char	*tmp;

	head = list_read;
	while (list_read)
	{
		list_read->line = ft_strcut(list_read->line, '#');
		list_read = list_read->next;
	}
	tmp = ft_strsub(head->line, 2, ft_strlen(head->line));
	free(head->line);
	head->line = ft_strdup(tmp);
	free(tmp);
	return (head);
}

static int		check_letters(t_lst *list_read)
{
	char	*tmp;
	int		i;

	while (list_read)
		list_read = list_read->next;
	i = -1;
	while (list_read)
	{
		tmp = list_read->line;
		while (tmp[++i])
			if (tmp[i] != '\n' && tmp[i] != ' ' &&
				!('0' <= tmp[i] && tmp[i] <= '9'))
				return (-1);
		i = -1;
		free(tmp);
		list_read = list_read->next;
	}
	return (1);
}

t_contrast		*valid_filling(t_contrast *main_list, t_lst *list_read)
{
	if (ft_strncmp(list_read->line, "P2\0", 3) == 0 ||
		ft_strncmp(list_read->line, "P2 ", 3) == 0)
	{
		list_read = cut_sharps(list_read);
		if (check_letters(list_read) == 1)
		{
			main_list = create_arr_int(list_read, main_list);
			return (main_list);
		}
	}
	main_list->size_map = 0;
	return (main_list);
}
