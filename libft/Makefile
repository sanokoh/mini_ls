# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 17:16:08 by ksano             #+#    #+#              #
#    Updated: 2020/10/25 11:44:31 by ksano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f
INCDIR	=	./
SRCDIR	=	./
SRCNAME	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_itoa.c ft_atoi.c ft_strmapi.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c
SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))
OBJS	=	$(SRCS:.c=.o)
BONUS	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS	=	$(BONUS:.c=.o) $(OBJS)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
all: $(NAME)
.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
bonus: $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: clean fclean all re bonus
