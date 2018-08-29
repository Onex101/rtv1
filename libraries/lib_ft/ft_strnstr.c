/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:19:09 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/15 07:49:47 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			crt;

	i = 0;
	crt = 1;
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (*(s1 + i) && i < n)
	{
		j = 0;
		if (*(s1 + i) == *(s2 + 0))
		{
			k = i;
			crt = 1;
			while (*(s1 + k) && *(s2 + j) && j < n && k < n)
				if (*(s1 + k++) != *(s2 + j++))
					crt = 0;
			if (crt && !*(s2 + j))
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
