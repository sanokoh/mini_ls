/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:21:11 by ksano             #+#    #+#             */
/*   Updated: 2020/10/28 09:22:31 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*buf_temp;

	buf_temp = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		buf_temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
