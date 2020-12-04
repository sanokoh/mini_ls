/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:09:22 by ksano             #+#    #+#             */
/*   Updated: 2020/12/04 15:28:05 by ksano            ###   ########.fr       */
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

void 				free_list(t_lslist *head);
void				print_list(t_lslist *list);
t_lslist			*new_list(t_lslist *head, struct dirent *dp, struct stat *stat_buf);
t_lslist			*add_list(t_lslist *head, t_lslist *new);

#endif
