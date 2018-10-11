/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:34:27 by tntini            #+#    #+#             */
/*   Updated: 2018/08/23 13:34:34 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(t_dir *list)
{
	t_dir		*temp;
	struct stat	fstat;
	char		*bytes;
	int			len;
	int			i;

	temp = list;
	while (temp != NULL)
	{
		lstat(temp->path, &fstat);
		ft_permission(temp, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putstr(" ");
		ft_putstr(get_user(fstat));
		i = 5;
		bytes = ft_itoa(fstat.st_size);
		len = ft_strlen(bytes);
		while (i-- > len)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(bytes, "  "));
		get_time(fstat, temp);
		temp = temp->next;
		if (temp != NULL)
			ft_putchar('\n');
	}
}

void	ft_rev_list(t_dir **head_ref)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void	ft_permission(t_dir *temp, struct stat fstat)
{
	if (temp->is_dir)
		ft_putchar('d');
	else
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr(" ");
}
