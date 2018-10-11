/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:33:02 by tntini            #+#    #+#             */
/*   Updated: 2018/08/23 13:33:12 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		cat;
	char	*p;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = ft_strlen(s1) + ft_strlen(s2);
	p = ((char *)malloc(sizeof(char) * cat + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}
