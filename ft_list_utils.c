/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:36:02 by ksano             #+#    #+#             */
/*   Updated: 2020/12/04 16:15:00 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "libft/libft.h"

void free_list(t_lslist *head)
{
	t_lslist *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->name);
		head->name = NULL;
		free(head);
		head = NULL;
		head = tmp;
	}
}

void print_list(t_lslist *list)
{
	while (list)
	{
		if (list->name[0] != '.')
		{
			ft_putendl_fd(list->name, 1);
		}
		list = list->next;
	}
}

t_lslist *new_list(t_lslist *head, struct dirent *dp, struct stat *stat_buf)
{
	t_lslist *new;

	if (!(new = (t_lslist *)malloc(sizeof(t_lslist))))
		return (NULL);
	new->name = ft_strdup(dp->d_name);
	new->stat_time = stat_buf->st_mtime;
	new->next = NULL;
	if (head == NULL)
		head = new;
	else
		head = add_list(head, new);
	return (head);
}

t_lslist *add_list(t_lslist *head, t_lslist *new)
{
	t_lslist *ls_tmp;

	if (new->stat_time <= head->stat_time)
	{
		new->next = head;
		head = new;
	}
	else
	{
		ls_tmp = head;
		while (ls_tmp != NULL)
		{
			if (ls_tmp->next == NULL)
			{
				ls_tmp->next = new;
				break;
			}
			else if ((new->stat_time >= ls_tmp->stat_time) &&
					 (ls_tmp->next->stat_time > new->stat_time))
			{
				new->next = ls_tmp->next;
				ls_tmp->next = new;
				break;
			}
			ls_tmp = ls_tmp->next;
		}
	}
	return (head);
}
