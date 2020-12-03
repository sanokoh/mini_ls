/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:40:02 by ksano             #+#    #+#             */
/*   Updated: 2020/10/25 17:23:15 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;

	if (!s)
		return (NULL);
	res = (char *)ft_calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	if (start >= ft_strlen((char *)s))
		return (res);
	else
		ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
