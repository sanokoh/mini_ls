/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:43:44 by ksano             #+#    #+#             */
/*   Updated: 2020/10/25 17:19:28 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_abs(int n)
{
	if (n < 0)
		return (n = -(n));
	return (n);
}

static int				intlen(int n)
{
	int		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char					*ft_itoa(int n)
{
	char				*res;
	unsigned int		abs_n;
	size_t				len;

	len = intlen(n);
	if (!(res = (char *)ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	abs_n = ft_abs(n);
	res[len] = '\0';
	while (abs_n > 0)
	{
		res[--len] = abs_n % 10 + '0';
		abs_n = abs_n / 10;
	}
	return (res);
}
