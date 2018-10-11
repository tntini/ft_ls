/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:30:18 by tntini            #+#    #+#             */
/*   Updated: 2018/08/23 13:30:25 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>

typedef struct		s_dir
{
	char			*dir;
	char			*path;
	time_t			time;
	int				is_dir;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_env
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
	char			*path;
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		sb;
	t_dir			*list;
}					t_env;

void				ft_permission(t_dir *temp, struct stat fstat);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				sort_list(t_dir **head, int (*cmp)(t_dir, t_dir), int done);
char				*get_user(struct stat fstat);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				get_time(struct stat fstat, t_dir *temp);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				do_list(t_env *e);
void				ft_putendl(char const *s);
void				ft_ls(t_env *e);
void				do_ls(char *dir, t_env *e);
void				print_l(t_dir *list);
int					ft_strcmp(const char *s1, const char *s2);
int					compare_strings(t_dir d1, t_dir d2);
void				ft_rev_list(t_dir **head_ref);
void				ft_putnbr(int n);
char				*ft_itoa(int n);
int					compare_time(t_dir d1, t_dir d2);
void				big_r(t_dir *list, t_env *e);
char				*ft_strnew(size_t size);
int					add_args(t_env *e, char *arg);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				print_l(t_dir *list);
int					main(int argc, char **argv);
#endif
