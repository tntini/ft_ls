/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:30:05 by tntini            #+#    #+#             */
/*   Updated: 2018/08/23 13:30:10 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_time(struct stat fstat, t_dir *temp)
{
	char	t_fmt[13];
	char	*str;
	char	buf[64];
	size_t	len;

	(void)fstat;
	str = ctime(&temp->time);
	ft_memcpy(t_fmt, &str[4], 12);
	t_fmt[12] = '\0';
	ft_putstr(t_fmt);
	ft_putstr(temp->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		len = readlink(temp->path, buf, 64);
		buf[len] = '\0';
		ft_putstr(buf);
	}
}

void	big_r(t_dir *list, t_env *e)
{
	t_dir *temp;

	temp = list;
	while (temp != NULL)
	{
		if (temp->is_dir == 1 && temp->dir[0] != '.')
			do_ls(temp->path, e);
		temp = temp->next;
	}
}

char	*get_user(struct stat fstat)
{
	char			*str;
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	str = ft_strjoin(ft_strjoin(pw->pw_name, "  "), gr->gr_name);
	return (ft_strjoin(str, " "));
}

void	do_list(t_env *e)
{
	e->list = (t_dir *)malloc(sizeof(t_dir));
	e->list->dir = ".";
	e->list->next = NULL;
}

void	ft_ls(t_env *e)
{
	t_dir	*temp;

	temp = e->list;
	while (temp != NULL)
	{
		do_ls(temp->dir, e);
		temp = temp->next;
	}
}
