/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:03:39 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/03 10:50:16 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int			ft_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && '0' <= s[i] && s[i] <= '9') ||
			(s[i - 1] == c && '0' <= s[i] && s[i] <= '9'))
			++words;
		i++;
	}
	return (words);
}

static int			*get_xy_grey(t_lst *head)
{
	char	**arr_char;
	int		index[2];
	int		*arr_int;
	int		res;

	index[0] = -1;
	index[1] = 0;
	arr_int = (int *)malloc(sizeof(int) * 3);
	while (head && index[1] < 3)
	{
		arr_char = ft_strsplit(head->line, ' ');
		while (arr_char[++index[0]] && index[1] < 3)
		{
			res = ft_atoi(arr_char[index[0]]);
			if (0 <= res && (index[1] < 2 || (index[1] > 1 && res <= 255)))
				arr_int[index[1]++] = res;
			else
				arr_int[0] = 0;
		}
		index[0] = -1;
		head = head->next;
		free(arr_char);
	}
	return (arr_int);
}

static int			*make_arr_pixel(t_lst *head, t_contrast *main_list)
{
	char	**arr_char;
	int		index[4];
	int		*arr_i;

	index[0] = -1;
	index[1] = 0;
	index[2] = 0;
	arr_i = (int *)malloc(sizeof(int) * main_list->lenght * main_list->height);
	while (head && index[1] < main_list->lenght * main_list->height)
	{
		arr_char = ft_strsplit(head->line, ' ');
		while (arr_char[++index[0]])
		{
			index[3] = ft_atoi(arr_char[index[0]]);
			if (0 <= index[3] && index[3] <= 255 && index[2] > 2)
				arr_i[index[1]++] = index[3];
			else
				arr_i[0] = -1;
			index[2]++;
		}
		index[0] = -1;
		head = head->next;
		free(arr_char);
	}
	return (arr_i);
}

static t_contrast	*fill_xy_grey(t_contrast *main_list, t_lst *head, int words)
{
	int		*arr_int;

	arr_int = get_xy_grey(head);
	if (arr_int[0] * arr_int[1] <= words - 3)
	{
		main_list->lenght = arr_int[0];
		main_list->height = arr_int[1];
		main_list->size_map = arr_int[0] * arr_int[1];
		main_list->max_grey_lvl = arr_int[2];
		main_list->mapping_pixel = make_arr_pixel(head, main_list);
		if (arr_int[0] == -1)
			main_list->size_map = 0;
		else
			main_list->size_map = arr_int[0] * arr_int[1];
	}
	else
		main_list->size_map = 0;
	free(arr_int);
	return (main_list);
}

t_contrast			*create_arr_int(t_lst *list_read, t_contrast *main_list)
{
	int		words;
	t_lst	*head;

	words = 0;
	head = list_read;
	while (list_read)
	{
		words += ft_words(list_read->line, ' ');
		list_read = list_read->next;
	}
	if (words >= 3)
		main_list = fill_xy_grey(main_list, head, words);
	else
		main_list->size_map = 0;
	return (main_list);
}
