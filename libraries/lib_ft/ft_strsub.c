/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:56:54 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/28 07:43:19 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!str || !(ret = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = str[start + i];
	return (ret);
}
