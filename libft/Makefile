# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/23 16:14:36 by hyson             #+#    #+#              #
#    Updated: 2021/01/11 15:49:50 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strmapi.c ft_itoa.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_calloc.c ft_atoi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_memcpy.c ft_memset.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c
OBJS = $(SRCS:%.c=%.o)

BONUS_SRCS = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstadd_front.c ft_lstnew.c

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

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
