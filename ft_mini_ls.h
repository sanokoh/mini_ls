/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:09:22 by ksano             #+#    #+#             */
/*   Updated: 2020/12/03 22:36:53 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <stdio.h>
# include <dirent.h>
# include <unistd.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>

# define PATH "./"

typedef struct		s_lslist
{
	char 			*name;
	int				stat_time;
	struct s_lslist	*next;
} 					t_lslist;

void safe_free(char **p);
void free_list(t_lslist *head);

#endif
