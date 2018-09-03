/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_prnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:24:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/03 18:20:21 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"
#include "lib_ft.h"

void	vec3_prnt(t_vec3 v)
{
	ft_putstr("X value = |");
	ft_putnbr(v.x);
	ft_putstr("| Y value = |");
	ft_putnbr(v.y);
	ft_putstr("| Z value = |");
	ft_putnbr(v.z);
	ft_putendl("|");	
}