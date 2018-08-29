/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:59:58 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 07:00:05 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*s_copy;
	int		i;
	int		len;

	if (s && f)
	{
		s_copy = s;
		i = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			f(i, (s_copy + i));
			i++;
		}
	}
}
