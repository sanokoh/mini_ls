/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:54:50 by ksano             #+#    #+#             */
/*   Updated: 2020/12/04 16:15:07 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"
#include "libft/libft.h"

void				safe_free(char **p)
{
	if (p)
	{
		free(*p);
		*p = NULL;
	}
	return ;
}

struct stat			get_stat(struct dirent *dp, char **path)
{
	struct stat		stat_buf;
	char			*tmp;

	tmp = *path;
	*path = ft_strjoin(PATH, dp->d_name);
	safe_free(&tmp);
	if (lstat(*path, &stat_buf) < 0 || !path)
	{
		ft_putendl_fd(strerror(ENOENT), 2);
		return (stat_buf);
	}
	return (stat_buf);
}

static void			ft_valid(int argc, DIR **dir, char **path)
{
	if (argc >= 2)
	{
		ft_putendl_fd(strerror(EINVAL), 2);
		return ;
	}
	*path = strdup(PATH);
	if (!(*path) || !(*dir = opendir(*path)))
	{
		ft_putendl_fd(strerror(ENOENT), 2);
		return ;
	}
	return ;
}

int					main(int argc, char **argv)
{
	t_lslist		*head;
	DIR				*dir;
	struct dirent	*dp;
	struct stat		stat_buf;
	char			*path;

	(void)argv;
	ft_valid(argc, &dir, &path);
	head = NULL;
	while ((dp = readdir(dir)))
	{
		stat_buf = get_stat(dp, &path);
		head = new_list(head, dp, &stat_buf);
	}
	print_list(head);
	if (dir != NULL)
		closedir(dir);
	safe_free(&path);
	free_list(head);
	return (0);
}
