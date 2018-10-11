/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tntini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 13:32:44 by tntini            #+#    #+#             */
/*   Updated: 2018/08/23 13:32:50 by tntini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		s1++;
		s2++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
