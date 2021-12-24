# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mortega- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 09:21:58 by mortega-          #+#    #+#              #
#    Updated: 2021/10/09 17:29:58 by mortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	fdf.c \
			read_file.c \
			images.c \
			draw_line.c \
			key_handler.c \
			utils.c \
			alg_utils.c

SRCS_BONUS	=	bonus/fdf_bonus.c \
				bonus/read_file_bonus.c \
				bonus/images_bonus.c \
				bonus/draw_line_bonus.c \
				bonus/key_handler_bonus.c \
				bonus/mouse_handler_bonus.c \
				bonus/utils_bonus.c \
				bonus/alg_utils_bonus.c

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

Libdir	=	./srcs/LIBFT

libname	=	libft.a

gnldir	=	./srcs/GNL

gnlname	=	gnl.a

mlxdir	=	./srcs/minilibx

mlxname	=	libmlx.a

Lib		=	$(Libdir)/$(libname)

Gnl		=	$(gnldir)/$(gnlname)

Mlx		=	$(mlxdir)/$(mlxname)

NAME	=	fdf

NAME_BONUS	=	fdfbonus

CFLAGS	=	-g -Wall -Werror -Wextra -Imlx

.c.o:
			@gcc ${CFLAGS} -I./srcs/minilibx -c $< -o ${<:.c=.o}

$(NAME):	${OBJS} ${Lib} ${Gnl} ${Mlx}
			@gcc -L./srcs/minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} ${Lib} ${Gnl} ${Mlx}

bonus:		${OBJS_BONUS} ${Lib} ${Gnl} ${Mlx}
			@gcc -L./srcs/minilibx -lmlx -framework OpenGL -framework AppKit -o ${NAME_BONUS} ${OBJS_BONUS} ${Lib} ${Gnl} ${Mlx}

all:		${NAME}


$(Lib):
			@make -C ${Libdir} > /dev/null 2>&1

$(Gnl):
			@make -C ${gnldir} > /dev/null 2>&1

$(Mlx):
			@make -C ${mlxdir} > /dev/null 2>&1

clean:
			@rm -f ${OBJS}
			@rm -f ${OBJS_BONUS}
			@make -s -C ${Libdir} clean
			@make -s -C ${gnldir} clean
			@make -s -C ${mlxdir} clean

fclean:		clean
			rm -f ${NAME}
			rm -f ${NAME_BONUS}
			@make -s -C ${Libdir} fclean
			@make -s -C ${gnldir} fclean
			@make -s -C ${mlxdir} clean

re:			fclean all

.PHONY:		all clean fclean re
