# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meoneida <meoneida@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 19:03:46 by meoneida          #+#    #+#              #
#    Updated: 2021/10/03 23:00:14 by meoneida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			=	$(shell uname -s)

NAME		=	so_long

SRCS		=	srcs/so_long.c\
				srcs/map.c\
				srcs/utils_1.c\
				srcs/utils_2.c\
				srcs/bonus.c
				
OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f
CC			=	gcc -g

LMLXDIR		=	./minilibx-linux/
HEADERS		=	./includes

CFLAGS		=	-Wall -Wextra -Werror -I$(HEADERS) -I$(LMLXDIR)

LMLXFLAGS	=	-L $(LMLXDIR) -lmlx -lm -lX11 -lXext -D LINUX

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LMLXFLAGS) -o $(NAME)

.PHONY:		all clean fclean re		
			
all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
