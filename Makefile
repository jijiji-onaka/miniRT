# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/25 15:44:15 by tjinichi          #+#    #+#              #
#    Updated: 2020/10/30 08:14:21 by tjinichi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc

CFLAGS = -Wall -Werror -Wextra

FLAGS = -L ./libft -lft ./libft/libft.a

SRCS =	srcs/main.c \
		srcs/read_file.c \
		srcs/free_all_lst.c \
		srcs/ft_raytracing.c \
		srcs/screen.c \
		srcs/error_exit.c \
		srcs/error_range.c \
		srcs/hash.c \
		srcs/bmp.c \
		srcs/color.c \
		srcs/minirt.c \
		srcs/key_hook.c \
		srcs/solve_check.c \
		srcs/object/sphere.c \
		srcs/object/cylinder.c \
		srcs/object/cylinder2.c \
		srcs/object/triangle.c \
		srcs/object/square.c \
		srcs/object/plane.c \
		srcs/object/disk.c \
		srcs/object/object.c \
		srcs/environment/ambient_light.c \
		srcs/environment/camera.c \
		srcs/environment/light.c \
		srcs/environment/resolution.c \

BONUSSRCS =	bonus/main.c \
		bonus/read_file.c \
		bonus/object.c \
		bonus/free_all_lst.c \
		bonus/ft_raytracing.c \
		bonus/screen.c \
		bonus/error_exit.c \
		bonus/error_range.c \
		bonus/hash.c \
		bonus/bmp.c \
		bonus/color.c \
		bonus/minirt.c \
		bonus/key_hook.c \
		bonus/solve_check.c \
		bonus/object/sphere.c \
		bonus/object/cylinder.c \
		bonus/object/cylinder2.c \
		bonus/object/triangle.c \
		bonus/object/square.c \
		bonus/object/plane.c \
		bonus/object/disk.c \
		bonus/environment/ambient_light.c \
		bonus/environment/camera.c \
		bonus/environment/light.c \
		bonus/environment/resolution.c \

OBJS = ${SRCS:.c=.o}
BONUSOBJS = ${BONUSSRCS:.c=.o}

LIBS = 	libft/libft.a

all: $(NAME)
# $(LIBS):
# 	$(MAKE) -C ./Libft

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) libmlx.dylib

$(LIBS): FORCE
	make -C ./libft

FORCE:

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bclean:
	rm -f bmps/*.bmp

chmod:
	chmod 700 *.bmp

bonus: $(LIBS) $(BONUSOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUSOBJS) $(LIBS) libmlx.dylib

.PHONY: all clean fclean re FORCE bclean chmod bonus


debag: $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -g -fsanitize=address -o dbg $(OBJS) $(LIBS) libmlx.dylib

# leak: $(OBJS) $(LIBS)
# 	$(CC) $(CFLAGS) -g -fsanitize=address -o leak $(OBJS) $(LIBS) libmlx.dylib
# 	ASAN_OPTIONS=detect_leaks=1 ./leak ${ARG}

# leaks:
# 	ASAN_OPTIONS=detect_leaks=1 ./leak ${ARG}
