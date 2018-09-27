/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 07:00:38 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:17:21 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;
	int		l;

	if (s1 && s2)
	{
		l = ft_strlen(s1);
		i = 0;
		while (s1[i] != '\0' && i < l)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
