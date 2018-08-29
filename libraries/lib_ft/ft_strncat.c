/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:18:25 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:18:26 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	int		j;
	char	*dest_copy;

	i = 0;
	j = (int)ft_strlen(dest);
	dest_copy = dest;
	while (i < (int)n && *(src + i))
	{
		*(dest_copy + j) = *(src + i);
		i++;
		j++;
	}
	*(dest_copy + j) = '\0';
	return (dest);
}
