/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:00:17 by ksano             #+#    #+#             */
/*   Updated: 2020/10/25 17:20:20 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	if (dst == src)
		return (dst);
	d_temp = (unsigned char *)dst;
	s_temp = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d_temp[i] = s_temp[i];
		i++;
	}
	return (dst);
}
