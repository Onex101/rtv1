/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:59:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 06:59:51 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

void	ft_striter(char *s, void (*f)(char *))
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
			f(s_copy + i);
			i++;
		}
	}
}
