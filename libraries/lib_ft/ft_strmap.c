/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:58:50 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 06:58:57 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r_str;
	int		i;

	if (!s && !f)
		return (NULL);
	r_str = ft_strnew(ft_strlen(s));
	if (r_str)
	{
		i = 0;
		while (*(s + i))
		{
			r_str[i] = (*f)(s[i]);
			i++;
		}
		return (r_str);
	}
	return (NULL);
}
