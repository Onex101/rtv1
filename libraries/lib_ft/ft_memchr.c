/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:01:09 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/16 17:01:19 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*s_copy;
	size_t		i;

	s_copy = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (*(s_copy + i) == (char)c)
		{
			return ((void *)s_copy + i);
		}
		i++;
	}
	return (NULL);
}
