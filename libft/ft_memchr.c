/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:46:05 by ksano             #+#    #+#             */
/*   Updated: 2020/10/29 10:39:24 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src_temp;
	size_t			i;

	src_temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src_temp[i] == (unsigned char)c)
		{
			return (&src_temp[i]);
		}
		i++;
	}
	return (NULL);
}
