/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:58:27 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 06:58:33 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r_str;
	int		i;

	if (!s || !f)
		return (NULL);
	r_str = ft_strnew(ft_strlen(s));
	if (r_str)
	{
		i = 0;
		while (*(s + i))
		{
			r_str[i] = (*f)(i, s[i]);
			i++;
		}
		return (r_str);
	}
	return (NULL);
}
