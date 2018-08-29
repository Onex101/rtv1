/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:00:55 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/22 13:19:21 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		size;
	char	**ret;

	if (!s)
		return (NULL);
	size = ft_strcount(s, c);
	ret = (char **)ft_memalloc(sizeof(char *) * size + 1);
	if (!ret)
		return (NULL);
	ret = ft_poparr(ret, s, c, size);
	if (!ret)
		return (NULL);
	return (ret);
}
