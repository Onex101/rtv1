/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:17:24 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:17:27 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strdup(const char *str)
{
	char *des;

	des = malloc(ft_strlen(str) + 1);
	if (!des)
		return (NULL);
	ft_strcpy(des, str);
	return (des);
}
