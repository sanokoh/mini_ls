/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:02:35 by ksano             #+#    #+#             */
/*   Updated: 2020/10/27 21:26:33 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_array(char const *s, char c)
{
	size_t		count;

	count = 0;
	if (c == '\0' && *s)
		return (1);
	if (s != NULL)
	{
		while (*s)
		{
			while (*s == c)
				s++;
			if (!(*s))
				break ;
			while (*s != c && *s)
				s++;
			count++;
		}
	}
	return (count);
}

static int		do_split(char **res, char const *s, char c, size_t num_array)
{
	size_t		i;
	size_t		len;
	size_t		index;
	size_t		start;

	i = 0;
	index = 0;
	while (index < num_array)
	{
		len = 0;
		while (s[i] == c)
			i++;
		start = i;
		while ((s[i] != c) && s[i])
		{
			i++;
			len++;
		}
		if (!(res[index] = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		ft_strlcpy(res[index], &s[start], len + 1);
		index++;
	}
	res[index] = NULL;
	return (1);
}

static void		free_split(char **res)
{
	int			i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
}

char			**ft_split(char const *s, char c)
{
	char		**res;
	size_t		num_array;

	if (!s)
		return (NULL);
	num_array = count_array(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (num_array + 1))))
		return (NULL);
	if (!(do_split(res, s, c, num_array)))
	{
		free_split(res);
		return (NULL);
	}
	return (res);
}
