# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyson <hyson@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 17:44:17 by hyson             #+#    #+#              #
#    Updated: 2021/11/16 20:36:42 by hyson            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#								I N S T  V A R				   			       #
#------------------------------------------------------------------------------#

CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
CDEBUG		= 	-fsanitize=address -g
RM			= 	rm -f

#------------------------------------------------------------------------------#
#									F I L E									   #
#------------------------------------------------------------------------------#

NAME		=	pipex
HEADER		=	./includes/
FOLDER		=	./srcs/
D_FT		=	./ft_functions/
D_CTX		=	./context/
SRC_LIST	=	main.c						\
				$(D_CTX)term.c				\
				$(D_CTX)parser.c			\
				$(D_FT)ft_atoi.c			\
				$(D_FT)ft_calloc.c			\
				$(D_FT)ft_free.c			\
				$(D_FT)ft_isdigit.c			\
				$(D_FT)ft_isspace.c			\
				$(D_FT)ft_memset.c			\
				$(D_FT)ft_putchar_fd.c		\
				$(D_FT)ft_putendl_fd.c		\
				$(D_FT)ft_putnbr_fd.c		\
				$(D_FT)ft_putstr_fd.c		\
				$(D_FT)ft_strlen.c			\
				$(D_FT)ft_strlcpy.c			\
				$(D_FT)ft_strdup.c			\
				$(D_FT)ft_strnstr.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

#------------------------------------------------------------------------------#
#								T	A	R	G	E	T						   #
#------------------------------------------------------------------------------#

%.o			:	%.c
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(OBJ)

#------------------------------------------------------------------------------#
#								R	U	L	E							       #
#------------------------------------------------------------------------------#

.PHONY		: 	all
all			: 	$(NAME)

.PHONY		:	clean
clean		:
				@$(RM) $(OBJ)

.PHONY		:	fclean
fclean		: 	clean
				@$(RM) $(NAME)

.PHONY		:	re
re			:	fclean all
