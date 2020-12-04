/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:10:44 by ksano             #+#    #+#             */
/*   Updated: 2020/10/21 09:56:53 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;

	if (!dst && !src)
		return (NULL);
	d_cpy = (unsigned char *)dst;
	s_cpy = (unsigned char *)src;
	if (s_cpy > d_cpy)
	{
		while (len--)
			*d_cpy++ = *s_cpy++;
	}
	else
	{
		d_cpy = d_cpy + len;
		s_cpy = s_cpy + len;
		while (len--)
			*(--d_cpy) = *(--s_cpy);
	}
	return (dst);
}
