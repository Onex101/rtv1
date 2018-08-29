/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 07:25:19 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/07 07:37:39 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strcdup(const char *str, char c)
{
	char	*des;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strclen((char *)str, c);
	des = (char *)malloc(len + 1);
	if (!des)
		return (NULL);
	ft_strncpy(des, str, len);
	return (des);
}
