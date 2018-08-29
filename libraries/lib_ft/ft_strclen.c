/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:14:24 by xrhoda            #+#    #+#             */
/*   Updated: 2018/06/04 10:22:09 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int	ft_strclen(char *str, char c)
{
	int count;

	if (!str)
		return (-1);
	count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			return (count);
		count++;
		str++;
	}
	return (count);
}
