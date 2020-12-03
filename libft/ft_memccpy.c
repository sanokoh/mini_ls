/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:00:17 by ksano             #+#    #+#             */
/*   Updated: 2020/10/22 10:47:50 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;

	d_cpy = (unsigned char *)dst;
	s_cpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d_cpy[i] = s_cpy[i];
		if (s_cpy[i] == (unsigned char)c)
		{
			return (&d_cpy[i + 1]);
		}
		i++;
	}
	return (NULL);
}
