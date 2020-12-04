/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:54:33 by ksano             #+#    #+#             */
/*   Updated: 2020/10/17 19:28:34 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_putnbr_each_fd(long n, int fd)
{
	if (n / 10 == 0)
	{
		ft_putchar_fd('0' + n, fd);
		return ;
	}
	ft_putnbr_each_fd(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void				ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_each_fd((-1) * (long)n, fd);
	}
	else
		ft_putnbr_each_fd(n, fd);
}
