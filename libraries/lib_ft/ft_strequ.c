/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:00:38 by xrhoda            #+#    #+#             */
/*   Updated: 2018/05/21 07:00:44 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"
#include <stdio.h>

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		l;

	
	if (s1 && s2)
	{
		l = ft_strlen(s1);
		printf("s1 len = %d\n", l);
		i = 0;
		while (s1[i] != '\0' && i < l)
		{
			printf("s1[%d] = [%c]  s2[%d] = [%c]\n", i, s1[i], i, s2[i]);
			if (s1[i] != s2[i])
			{
				printf("failed at :s1[%d] = [%c]  s2[%d] = [%c]\n", i, s1[i], i, s2[i]);
				return (0);
			}
			i++;
		}
		printf("streq match\n");
		return (1);
	}
	return (0);
}
