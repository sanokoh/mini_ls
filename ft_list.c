/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:36:02 by ksano             #+#    #+#             */
/*   Updated: 2020/12/03 22:36:56 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "libft.h"

void safe_free(char **p)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
	return;
}

void free_list(t_lslist *head)
{
	t_lslist *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->name);
		free(head);
		head = tmp;
	}
}
