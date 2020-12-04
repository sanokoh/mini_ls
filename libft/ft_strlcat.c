/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:07:17 by ksano             #+#    #+#             */
/*   Updated: 2020/10/22 10:49:25 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	if (d_len < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && d_len + i < dstsize - 1)
		{
			dst[j++] = src[i++];
		}
		dst[j] = '\0';
	}
	if (d_len >= dstsize)
		d_len = dstsize;
	return (d_len + s_len);
}
