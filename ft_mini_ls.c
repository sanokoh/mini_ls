/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:54:50 by ksano             #+#    #+#             */
/*   Updated: 2020/12/03 13:55:38 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "libft.h"

#define PATH "./"

typedef struct s_lslist
{
	char 			*name;
	int				stat_time;
	struct s_lslist	*next;
} 					t_lslist;

void safe_free(char **p)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
	return;
}

t_lslist *add_list(struct dirent *dp, struct stat *stat_buf)
{
	t_lslist	*new;
	int 	i;
	char	*tmp;

	if (!(new = (t_lslist *)malloc(sizeof(t_lslist))))
		return (NULL);
	tmp = new->name;
	new->name = ft_strdup(dp->d_name);
	safe_free(&tmp);
	new->stat_time = stat_buf->st_mtime;
	new->next = NULL;
	return (new);
}

int main(int argc, char **argv)
{
	t_lslist *head;
	t_lslist *ls_tmp;
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
		ls_tmp = head;
		head = add_list(dp, &stat_buf);
		head->next = ls_tmp;
	}
	ls_tmp = head;
	while (ls_tmp->next)
	{
		if (ls_tmp->name[0] != '.')
			ft_putendl_fd(ls_tmp->name, 1);
		ls_tmp = ls_tmp->next;
	}
	if (dir != NULL)
		closedir(dir);
	safe_free(&path);
	return (0);
}


/*
** 	while ((dp = readdir(dir)))
** 	{
** 		tmp = path;
** 		path = ft_strjoin(PATH, dp->d_name);
** 		safe_free(&tmp);
** 		if (lstat(path, &stat_buf) < 0 || !path)
** 		{
** 			ft_putendl_fd(strerror(ENOENT), 2);
** 			return (1);
** 		}
** 		if (dp->d_name[0] != '.')
** 			ft_putendl_fd(dp->d_name, 1);
** 	}
*/
