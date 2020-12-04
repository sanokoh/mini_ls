# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 17:16:08 by ksano             #+#    #+#              #
#    Updated: 2020/12/04 16:26:57 by ksano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_mini_ls
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
INCDIR	=	./
SRCDIR	=	./
LIBDIR	=	./libft/

SRCNAME	=	ft_mini_ls.c ft_list_utils.c
LIBNAME =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_itoa.c ft_atoi.c ft_strmapi.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c
SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))
LIBS	=	$(addprefix $(LIBDIR), $(LIBNAME))

OBJS	=	$(SRCS:.c=.o)
LOBJS	=	$(LIBS:.c=.o)

$(NAME): $(OBJS) $(LOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./$(LIBNAME:.c=.o)
all: $(NAME)
.c.o:
	$(CC) $(CFLAGS) -I $(SRCDIR) -c $<
	$(CC) $(CFLAGS) -I $(LIBDIR) -c $<
clean:
	$(RM) $(OBJS)
	$(RM) $(LOBJS)
	$(RM) ./$(LIBNAME:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
