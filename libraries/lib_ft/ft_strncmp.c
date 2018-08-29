/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:18:39 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:18:40 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int		i;

	i = 0;
	while (*(str1 + i) && *(str1 + i) == *(str2 + i) && i < (int)n - 1)
		i++;
	if (n)
		return (*((unsigned char *)str1 + i) - *((unsigned char *)str2 + i));
	return (0);
}
