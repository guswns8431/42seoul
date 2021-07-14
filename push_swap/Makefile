# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseo <jseo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 16:55:40 by hyson             #+#    #+#              #
#    Updated: 2021/07/14 18:13:47 by jseo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------------------------------------------------
# INST VAR
# -----------------------------------------------------------------------------

CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror
CDEBUG		=		-fsanitize=address -g
RM			=		rm -f

# -----------------------------------------------------------------------------
# FILE VAR
# -----------------------------------------------------------------------------

NAME		=		push_swap
HEADER		=		./includes/
FOLDER		=		./srcs/
D_CTX		=		context/
D_FT		=		ft_functions/
D_INST		=		instructions/
D_TEST		=		test/
SRC_LIST	=		main.c					\
					$(D_CTX)logic.c			\
					$(D_CTX)node.c			\
					$(D_CTX)term.c			\
					$(D_FT)ft_atoi.c		\
					$(D_FT)ft_calloc.c		\
					$(D_FT)ft_free.c		\
					$(D_FT)ft_isdigit.c		\
					$(D_FT)ft_isspace.c		\
					$(D_FT)ft_memset.c		\
					$(D_FT)ft_putchar_fd.c	\
					$(D_FT)ft_putendl_fd.c	\
					$(D_FT)ft_putnbr_fd.c	\
					$(D_FT)ft_putstr_fd.c	\
					$(D_FT)ft_strlen.c		\
					$(D_INST)iter.c			\
					$(D_INST)push.c			\
					$(D_INST)rotate.c		\
					$(D_INST)rrotate.c		\
					$(D_INST)swap.c			\
					$(D_TEST)push.c			\
					$(D_TEST)rotate.c		\
					$(D_TEST)rrotate.c		\
					$(D_TEST)swap.c
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:.c=.o)

# -----------------------------------------------------------------------------
# Target Generating
# -----------------------------------------------------------------------------

%.o			:	%.c
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $@ -c $<

$(NAME)		:	$(OBJ)
				@$(CC) $(CFLAGS) $(CDEBUG) -I $(HEADER) -o $(NAME) $(OBJ)

# -----------------------------------------------------------------------------
# Rule
# -----------------------------------------------------------------------------

.PHONY		:	all
all			:	$(NAME)

.PHONY		:	clean
clean		:
				@$(RM) $(OBJ)

.PHONY		:	fclean
fclean		:	clean
				@$(RM) $(NAME)

.PHONY		:	re
re			:	fclean all

.PHONY		:	norm
norm		:
				@norminette

