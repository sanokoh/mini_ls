/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:38:42 by ksano             #+#    #+#             */
/*   Updated: 2020/10/28 10:15:19 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int					ft_atoi(const char *str)
{
	int				sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		if ((res >= (unsigned long)(-1) * (LONG_MIN)) && sign < 0)
			return (0);
		else if ((res >= LONG_MAX) && sign > 0)
			return (-1);
		str++;
	}
	return ((int)(res * sign));
}
