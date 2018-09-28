/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 17:02:14 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 20:33:13 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
