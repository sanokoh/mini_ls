/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:54:50 by ksano             #+#    #+#             */
/*   Updated: 2020/12/03 23:11:25 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "libft.h"

void print_list(t_lslist *list)
{
	while (list)
	{
		if (list->name[0] != '.')
			ft_putendl_fd(list->name, 1);
		list = list->next;
	}
}

static t_lslist *add_list(struct dirent *dp, struct stat *stat_buf)
{
	t_lslist *new;
	t_lslist *tmp;

	if (!(new = (t_lslist *)malloc(sizeof(t_lslist))))
		return (NULL);
	new->name = ft_strdup(dp->d_name);
	new->stat_time = stat_buf->st_mtime;
	new->next = NULL;
	return (new);
}

int main(int argc, char **argv)
{
	t_lslist *head;
	t_lslist *ls_tmp;
	t_lslist *new;
	DIR *dir;
	struct dirent *dp;
	struct stat stat_buf;
	char *path;
	char *tmp;

	if (argc >= 2)
	{
		ft_putendl_fd(strerror(EINVAL), 2);
		return (1);
	}
	path = strdup(PATH);
	if (!path || !(dir = opendir(path)))
	{
		ft_putendl_fd(strerror(ENOENT), 2);
		return (1);
	}
	head = NULL;

	while ((dp = readdir(dir)))
	{
		tmp = path;
		path = ft_strjoin(PATH, dp->d_name);
		safe_free(&tmp);
		if (lstat(path, &stat_buf) < 0 || !path)
		{
			ft_putendl_fd(strerror(ENOENT), 2);
			return (1);
		}
		new = add_list(dp, &stat_buf);
		if (head == NULL)
			head = new;
		else if (new->stat_time <= head->stat_time)
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
				else if ((new->stat_time >= ls_tmp->stat_time) && (ls_tmp->next->stat_time > new->stat_time))
				{
					new->next = ls_tmp->next;
					ls_tmp->next = new;
					break;
				}
				ls_tmp = ls_tmp->next;
			}
		}
	}
	ls_tmp = head;
	print_list(ls_tmp);
	if (dir != NULL)
		closedir(dir);
	free_list(head);
	safe_free(&path);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	t_lslist *head;
// 	t_lslist *ls_tmp;
// 	t_lslist *new;
// 	DIR *dir;
// 	struct dirent *dp;
// 	struct stat stat_buf;
// 	char *path;
// 	char *tmp;

// 	if (argc >= 2)
// 	{
// 		ft_putendl_fd(strerror(EINVAL), 2);
// 		return (1);
// 	}
// 	path = strdup(PATH);
// 	if (!path || !(dir = opendir(path)))
// 	{
// 		ft_putendl_fd(strerror(ENOENT), 2);
// 		return (1);
// 	}
// 	head = NULL;
// 	while ((dp = readdir(dir)))
// 	{
// 		tmp = path;
// 		path = ft_strjoin(PATH, dp->d_name);
// 		safe_free(&tmp);
// 		if (lstat(path, &stat_buf) < 0 || !path)
// 		{
// 			ft_putendl_fd(strerror(ENOENT), 2);
// 			return (1);
// 		}
// 		new = add_list(dp, &stat_buf);
// 		if (head == NULL)
// 			head = new;
// 		else if (new->stat_time <= head->stat_time)
// 		{
// 			new->next = head;
// 			head = new;
// 		}
// 		else
// 		{
// 			ls_tmp = head;
// 			while (ls_tmp != NULL)
// 			{
// 				if (ls_tmp->next == NULL)
// 				{
// 					ls_tmp->next = new;
// 					break ;
// 				}
// 				else if ((new->stat_time >= ls_tmp->stat_time) && (ls_tmp->next->stat_time > new->stat_time))
// 				{
// 					new->next = ls_tmp->next;
// 					ls_tmp->next = new;
// 					break ;
// 				}
// 				ls_tmp = ls_tmp->next;
// 			}
// 		}
// 	}
// 	ls_tmp = head;
// 	while (ls_tmp)
// 	{
// 		if (ls_tmp->name[0] != '.')
// 			ft_putendl_fd(ls_tmp->name, 1);
// 		ls_tmp = ls_tmp->next;
// 	}
// 	if (dir != NULL)
// 		closedir(dir);
// 	safe_free(&path);
// 	return (0);
// }
