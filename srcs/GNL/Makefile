# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mortega- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/02 08:44:36 by mortega-          #+#    #+#              #
#    Updated: 2021/07/31 11:53:11 by mortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	get_next_line.c get_next_line_utils.c ft_count_lines.c

OBJS 	= 	${SRCS:.c=.o}

NAME 	=	 gnl.a

CFLAGS 	= 	-Wall -Werror -Wextra -D BUFFER_SIZE=9999

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
		
