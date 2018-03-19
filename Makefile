# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asvirido <asvirido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 14:27:54 by asvirido          #+#    #+#              #
#    Updated: 2018/02/03 15:47:45 by asvirido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MAIN = ft_contrast

NAME_THREAD = ft_contrast_th

FLAGS = -c -Wall -Wextra -Werror

HEADER = head.h

LIBFT = ./src/general/libft/ft_atoi.c 											\
		./src/general/libft/ft_bzero.c 											\
		./src/general/libft/ft_isdigit.c 										\
		./src/general/libft/ft_strcmp.c 										\
		./src/general/libft/ft_strcpy.c 										\
		./src/general/libft/ft_strdup.c 										\
		./src/general/libft/ft_strjoin.c 										\
		./src/general/libft/ft_strlen.c 										\
		./src/general/libft/ft_strsub.c 										\
		./src/general/libft/ft_putchar_fd.c 									\
		./src/general/libft/ft_putnbr_fd.c 										\
		./src/general/libft/ft_putstr_fd.c 										\
		./src/general/libft/ft_strncpy.c 										\
		./src/general/libft/ft_strncmp.c 										\
		./src/general/libft/ft_strsplit.c 										\
		./src/general/libft/ft_memchr.c 										\
		./src/general/libft/ft_memalloc.c 										\
		./src/general/libft/ft_strnew.c											\
		./src/general/libft/ft_strdel.c 										\
		./src/general/libft/ft_memdel.c 										\
		./src/general/libft/ft_memset.c 										\

LIST = 	./src/general/list/ft_nlstadd.c 										\
		./src/general/list/ft_nlstnew.c 										\

GENERAL = 	./src/general/get_next_line.c 										\
			./src/general/input_param.c 										\
			./src/general/ft_read.c 											\
			./src/general/init.c 												\
			./src/general/algo_contrast.c 										\
			./src/general/change_mapping.c 										\
			./src/general/save_file.c 											\
			./src/general/valid_filling.c 										\
			./src/general/create_arr_int.c 										\

THREAD =	./src/thread/get_borders.c 											\
			./src/thread/ft_copy.c 												\
			./src/thread/thread_change.c 										\
			./src/thread/thread_save_file.c 									\
			./src/thread/thread_change_mapping.c 								\
			./src/thread/read_from_file.c 										\
			./src/thread/ft_read_thread.c 										\

SRC_GEN = 	$(LIBFT)															\
			$(LIST) 															\
			$(GENERAL)															\
		
SRC_THREAD	=	$(THREAD)														\

MAIN_MAIN = main.c 																\

MAIN_THREAD = ./src/thread/thread_main.c 										\

BINS_GEN = $(SRC_GEN:.c=.o)

BINS_MAIN = $(MAIN_MAIN:.c=.o)

BINS_THREAD =	$(MAIN_THREAD:.c=.o)											\
				$(SRC_THREAD:.c=.o)

all: $(NAME_MAIN) $(NAME_THREAD)

$(NAME_MAIN): $(BINS_GEN) $(BINS_MAIN)
	gcc -o $(NAME_MAIN) $(BINS_GEN) $(BINS_MAIN)

$(NAME_THREAD): $(BINS_GEN) $(BINS_THREAD)
	gcc -o $(NAME_THREAD) $(BINS_GEN) $(BINS_THREAD)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -o $@ $<

clean:
	/bin/rm -f $(BINS_GEN) $(BINS_MAIN) $(BINS_THREAD)

clean_ft_contrast:
	 /bin/rm -f $(BINS_GEN) $(BINS_MAIN)

clean_ft_contrast_th:
	 /bin/rm -f $(BINS_GEN) $(BINS_THREAD)

fclean: clean
	/bin/rm -f $(NAME_MAIN) $(NAME_THREAD)

fclean_ft_contrast: clean_ft_contrast
	/bin/rm -f $(NAME_MAIN)

fclean_ft_contrast_th: clean_ft_contrast_th
	/bin/rm -f $(NAME_THREAD)

re: fclean all

re_ft_contrast: fclean_ft_contrast $(NAME_MAIN)

re_ft_contrast_th: fclean_ft_contrast_th $(NAME_THREAD)
