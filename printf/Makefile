# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 16:14:36 by hyson             #+#    #+#              #
#    Updated: 2021/04/19 15:00:12 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS =	ft_atoi.c \
		ft_check_option.c \
		ft_check_option_type.c \
		ft_check_type.c \
		ft_is_type.c \
		ft_memset.c \
		ft_nbrlen.c \
		ft_print_percent.c \
		ft_print_type_c.c \
		ft_print_type_d.c \
		ft_print_type_lowx.c \
		ft_print_type_p.c \
		ft_print_type_s.c \
		ft_print_type_u.c \
		ft_print_type_upx.c \
		ft_printf.c \
		ft_process_precision.c \
		ft_process_precision_num.c \
		ft_process_width.c \
		ft_putnbr_base.c \
		ft_strlen.c

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
