/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:31:06 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/21 11:32:20 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// int		ft_strcheck(const char *haystack, const char *needle)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	int		crt;

// 	if (!ft_strlen(needle))
// 		return ((char *)haystack);
// 	i = 0;
// 	crt = 0;
// 	while (*(haystack + i) && !crt)
// 	{
// 		if (*(haystack + i) == *(needle + 0))
// 		{
// 			j = 0;
// 			k = i;
// 			crt = 1;
// 			while (*(needle + j))
// 				if (*(needle + j++) != *(haystack + k++))
// 					crt = 0;
// 			if (crt)
// 				return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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
