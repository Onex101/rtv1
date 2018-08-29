/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:16:38 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:16:41 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (*(str1 + i) && *(str1 + i) == *(str2 + i))
		i++;
	return (*((unsigned char *)str1 + i) - *((unsigned char *)str2 + i));
}
