# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 16:14:36 by hyson             #+#    #+#              #
#    Updated: 2021/03/20 09:50:44 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS =	ft_printf.c \
	  	ft_strlen.c \

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

bonus : $(NAME)
	$(CC) $(FLAGS) -c $(BONUS_SRCS)
	ar -rc $(NAME) $(BONUS_OBJS)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
