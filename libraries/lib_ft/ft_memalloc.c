/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:02:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 07:02:45 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	mem = (void *)malloc(size);
	if (mem)
	{
		return (ft_memset(mem, 0, size));
	}
	return (NULL);
}
