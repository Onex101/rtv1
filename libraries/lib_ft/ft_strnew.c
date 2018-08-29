/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:57:26 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 06:57:34 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size);
	return (str);
}
