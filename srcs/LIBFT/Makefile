# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mortega- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 16:53:59 by mortega-          #+#    #+#              #
#    Updated: 2021/10/21 14:03:32 by mortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_memset.c ft_atoi.c ft_hextoi.c ft_atof.c ft_bzero.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_memmove.c ft_memccpy.c ft_strlcpy.c ft_strlcat.c ft_memchr.c ft_putnbr_base.c ft_memcmp.c ft_strlen.c ft_strchr.c ft_strchrnum.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isnumber.c ft_isspace.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_split_count.c ft_split_free.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS		= ${SRCS:.c=.o}

SRCS_BONUS	= lst/ft_lstnew.c lst/ft_lstadd_front.c lst/ft_lstsize.c lst/ft_lstlast.c lst/ft_lstadd_back.c lst/ft_lstdelone.c lst/ft_lstclear.c lst/ft_lstiter.c lst/ft_lstmap.c

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

SRCS_MATH	= $(wildcard math/*.c)

OBJS_MATH	= ${SRCS_MATH:.c=.o}

NAME		= libft.a

.c.o:
			gcc -Wall -Werror -Wextra -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

lst:		${OBJS_BONUS}
			ar -rc ${NAME} ${OBJS_BONUS}
			ranlib ${NAME}

math:		${OBJS_MATH}
			ar -rc ${NAME} ${OBJS_MATH}
			ranlib ${NAME}

clean:
			@rm -f ${OBJS} ${OBJS_BONUS} ${OBJS_MATH}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
