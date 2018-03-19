/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukyane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:00:45 by alukyane          #+#    #+#             */
/*   Updated: 2018/02/04 22:11:00 by alukyane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head.h"

char		*ft_found_n(char *readbuf, size_t ret, t_gnl *curr, void *tmp)
{
	char	*chr;
	char	*res;
	size_t	len;
	char	*chr2;

	len = 0;
	chr = ft_memchr(readbuf, '\n', ret);
	chr++;
	ft_memdel(&(curr->content));
	curr->content = ft_strncpy(ft_strnew(ret), chr, ret);
	curr->size = ft_strlen(curr->content);
	chr2 = readbuf;
	while (*chr2 != '\0' && *chr2++ != '\n')
		len++;
	chr2 = ft_strncpy(ft_strnew(len), readbuf, len);
	res = ft_strjoin(tmp, chr2);
	ft_memdel(&tmp);
	ft_strdel(&chr2);
	return (res);
}

char		*ft_check_content(t_gnl *curr, size_t ret, size_t len, char *chr)
{
	void	*tmp;
	char	*tmp_cont;

	while (curr->content && chr[len] != '\0' && chr[len] != '\n' &&
		len < curr->size)
		len++;
	tmp_cont = ft_strsub(curr->content, len + 1, curr->size);
	if (len)
	{
		tmp = ft_strncpy(ft_strnew(len), curr->content, len);
		ft_memdel(&(curr->content));
		curr->content = chr[len] != '\0' ? ft_strdup(tmp_cont) : NULL;
		curr->size = chr[len] != '\0' ? ft_strlen(curr->content) : 0;
		ft_strdel(&tmp_cont);
		return (tmp);
	}
	else
	{
		ft_memdel(&(curr->content));
		curr->content = tmp_cont ? ft_strdup(tmp_cont) : NULL;
		curr->size = curr->content ? ft_strlen(curr->content) : 0;
		curr->flag = !(ret) ? 1 : 0;
		ft_strdel(&tmp_cont);
		return (ft_strdup(""));
	}
}

char		*ft_read_from_file(t_gnl *curr)
{
	void	*tmp;
	size_t	ret[2];
	char	*readbuf;
	char	*chr;

	readbuf = (char *)malloc(sizeof(char) * (BUFF_SIZE_THREAD + 1));
	ret[1] = 0;
	while (!(ft_memchr(curr->content, '\n', curr->size)) &&
			(ret[0] = read(curr->fd, readbuf, BUFF_SIZE_THREAD)) != 0)
	{
		readbuf[ret[0]] = '\0';
		tmp = ft_strncpy(ft_strnew(curr->size), curr->content, curr->size);
		if (ft_memchr(readbuf, '\n', ret[0]))
			return (ft_found_n(readbuf, ret[0], curr, tmp));
		else
		{
			ft_memdel(&(curr->content));
			curr->content = ft_strjoin(tmp, readbuf);
			curr->size = ft_strlen(curr->content);
		}
		ft_memdel(&tmp);
	}
	chr = curr->content;
	free(readbuf);
	return (ft_check_content(curr, ret[0], ret[1], chr));
}

t_gnl		*get_current_fd(const int fd, t_gnl **list)
{
	t_gnl *current;

	current = *list;
	while (current)
	{
		if (current->fd == fd)
		{
			if (!(current->content))
				current->content = ft_memalloc(0);
			return (current);
		}
		current = current->next;
	}
	current = ft_memalloc(sizeof(t_gnl));
	current->size = 0;
	current->fd = fd;
	current->flag = 0;
	current->content = ft_memalloc(0);
	current->next = *list;
	*list = current;
	return (current);
}

int			read_from_file(const int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*current;
	char			*tmp;

	if (fd >= 0 && read(fd, "", 0) != -1)
	{
		current = get_current_fd(fd, &lst);
		tmp = ft_read_from_file(current);
		*line = tmp;
		if ((*line == NULL || ft_strcmp(*line, "") == 0)
			&& current->flag == 1)
			return (0);
		return (1);
	}
	return (-1);
}
