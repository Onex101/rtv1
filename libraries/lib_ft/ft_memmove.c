/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:15:44 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:15:45 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src_copy;
	char	*dst_copy;
	int		i;

	i = 0;
	dst_copy = (char *)dst;
	src_copy = (char *)src;
	if (src_copy < dst_copy)
	{
		while (n--)
			*(dst_copy + n) = *(src_copy + n);
	}
	else
	{
		while (i < (int)n)
		{
			*(dst_copy + i) = *(src_copy + i);
			i++;
		}
	}
	return (dst);
}
