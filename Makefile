# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 17:16:08 by ksano             #+#    #+#              #
#    Updated: 2020/12/03 17:58:22 by ksano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_mini_ls: ft_mini_ls.o
	gcc -o ft_mini_ls ft_mini_ls.o libft.a
ft_mini_ls.o: ft_mini_ls.c
	gcc -c ft_mini_ls.c
