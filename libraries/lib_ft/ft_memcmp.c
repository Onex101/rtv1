/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:15:12 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:15:15 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str1_copy;
	unsigned char	*str2_copy;
	size_t			i;

	i = 0;
	str1_copy = (unsigned char *)str1;
	str2_copy = (unsigned char *)str2;
	while (i < n && *(str1_copy + i) == *(str2_copy + i))
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (*(str1_copy + i) - *(str2_copy + i));
}
