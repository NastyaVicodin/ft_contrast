/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asvirido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:15:57 by asvirido          #+#    #+#             */
/*   Updated: 2017/03/09 15:54:51 by asvirido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);
void	*ft_memset(void *d, int c, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_strsplit(char const *s, char c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);

#endif
