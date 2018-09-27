/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:31:06 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 15:16:11 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_strcheck(const char *haystack, const char *needle)
{
	int		i;
	int		s;
	char	*ret;

	i = 0;
	s = 0;
	ret = (char *)haystack;
	if (needle[i] == '\0')
		return (1);
	while (ret[i])
	{
		s = 0;
		while (ret[i + s] == needle[s])
		{
			if (needle[s + 1] == '\0')
				return (1);
			s++;
		}
		i++;
	}
	return (0);
}
