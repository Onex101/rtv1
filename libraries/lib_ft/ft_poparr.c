/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:45:55 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/29 12:46:50 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	**ft_poparr(char **r, char const *s, char c, int size)
{
	int		a;
	int		i;

	if (!r)
		return (NULL);
	a = 0;
	while (*s != '\0' && a < size)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i] != '\0')
				i++;
			r[a++] = ft_strsub(s, 0, i);
			s = s + i;
		}
		s++;
	}
	r[a] = NULL;
	return (r);
}
