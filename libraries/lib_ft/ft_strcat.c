/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:16:09 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:16:11 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int			i;
	int			j;

	i = 0;
	j = (int)ft_strlen(dest);
	while (*(src + i))
	{
		*(dest + j) = *(src + i);
		j++;
		i++;
	}
	*(dest + j) = '\0';
	return (dest);
}
