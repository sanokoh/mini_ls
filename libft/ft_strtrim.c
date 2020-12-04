/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:53:44 by ksano             #+#    #+#             */
/*   Updated: 2020/10/15 09:40:32 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	head;
	size_t	tail;

	if (!s1)
		return (NULL);
	head = 0;
	while (s1[head] && ft_strchr(set, s1[head]))
		head++;
	tail = ft_strlen((char *)s1);
	while (tail > head && ft_strchr(set, s1[tail - 1]))
		tail--;
	res = (char *)ft_calloc(sizeof(*s1), (tail - head + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[head], tail - head + 1);
	return (res);
}
