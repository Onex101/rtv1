/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 08:12:39 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/15 08:12:57 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"
#include <stdio.h>

static	long	int	ft_getnum(const char *str, int sign)
{
	long int num;

	num = 0;
	while (*str)
	{
		if (ft_isdigit(*str))
			num = (num * 10) + (*(str) - 48);
		if (!ft_isdigit(*str))
			break ;
		str++;
		if (!ft_isdigit(*str))
			break ;
	}
	return (num * sign);
}

int					ft_atoi(const char *str)
{
	int num;
	int	count;
	int sign;

	sign = 1;
	count = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\f' || *str == '\v' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*(str) == '-')
			sign = -1;
		str++;
		count++;
		if (count > 1)
			return (0);
	}
	num = ft_getnum(str, sign);
	return ((int)num);
}
