/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:52:53 by ksano             #+#    #+#             */
/*   Updated: 2020/10/28 09:50:52 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack,
				const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	if (!(*needle))
		return (char *)(haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			temp = i;
			j = 1;
			while (needle[j] && haystack[++temp] == needle[j])
				j++;
			if (temp >= len)
				break ;
			if (!needle[j])
				return (char *)(haystack + i);
		}
	}
	return (NULL);
}
