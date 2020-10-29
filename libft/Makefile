# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 20:15:31 by tjinichi          #+#    #+#              #
#    Updated: 2020/10/26 04:06:12 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isspace.c \
		ft_stoi.c \
		ft_stod.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		ft_check_file_tail.c \
		count_2d.c \
		array_free_2d.c \
		ft_numlen.c \
		create_file_name.c \
		ft_stov.c \
		ft_strcmp.c \
		ft_strjoin_num.c \
		file_tail_number.c


BONUS =	ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstdelone.c \
		ft_lstmap.c \

OBJS = $(SRCS:.c=.o)
BONUSOBJS = $(BONUS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libvec3D
	cp ./libvec3D/libvec.a $(NAME)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
	make clean -C ./libvec3D
	$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	make fclean -C ./libvec3D
	$(RM) $(NAME)

re:	fclean all

bonus:	all $(BONUSOBJS)
	ar rcs $(NAME) $(BONUSOBJS)

.PHONY:	all clean fclean re bonus
