/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:29:46 by tntini            #+#    #+#             */
/*   Updated: 2018/08/23 13:29:51 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ls(t_dir *list, t_env *e, char *path)
{
	t_dir	*temp;

	if (e->t == 1)
		sort_list(&list, compare_time, 0);
	if (e->r == 1)
		ft_rev_list(&list);
	if (e->rr == 1)
		ft_putstr(ft_strjoin(path, ":\n"));
	if (e->l == 1)
		print_l(list);
	else
	{
		temp = list;
		while (temp != NULL)
		{
			ft_putstr(temp->dir);
			temp = temp->next;
			if (temp != NULL)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	if (e->rr == 1)
		big_r(list, e);
}

void	do_ls(char *dir, t_env *e)
{
	t_dir	*list;
	t_dir	*temp;

	list = NULL;
	if ((e->dirp = opendir(dir)) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			if (e->dp->d_name[0] != '.' || e->a == 1)
			{
				temp = (t_dir *)malloc(sizeof(t_dir));
				temp->dir = e->dp->d_name;
				temp->path = ft_strjoin(ft_strjoin(dir, "/"),
						e->dp->d_name);
				lstat(temp->path, &e->sb);
				temp->time = e->sb.st_mtime;
				if (S_ISDIR(e->sb.st_mode) == 1)
					temp->is_dir = 1;
				temp->next = list;
				list = temp;
			}
		}
		sort_list(&list, compare_strings, 0);
		ft_print_ls(list, e, dir);
	}
}
