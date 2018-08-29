/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 06:59:10 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 06:59:19 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*n_str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	n_str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
	if (n_str == NULL)
		return (NULL);
	while (*s1)
	{
		n_str[i++] = *s1++;
	}
	while (*s2)
	{
		n_str[i++] = *s2++;
	}
	return (n_str);
}
