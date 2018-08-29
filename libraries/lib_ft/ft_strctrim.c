/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:27:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/29 12:27:40 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strctrim(char const *s, char c)
{
	int		i;
	int		l;
	char	*sc;

	i = 0;
	l = ft_strlen(s) - 1;
	sc = ft_strdup(s);
	if (sc == NULL)
		return (NULL);
	if (*sc != c)
	{
		if (*(sc + l) != c)
			return (sc);
	}
	while (sc[l] == c)
		l--;
	sc[++l] = '\0';
	while (sc[i] == c)
	{
		i++;
	}
	return (sc + i);
}
