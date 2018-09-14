/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:54:00 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/14 14:03:05 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mac_key_press(int keycode)
{
	if (keycode == 53)
		exit (0);
}

void	linux_key_press(int keycode)
{
	if (keycode == 65307)
		exit (0);
}

int		key_press(int keycode, t_param *p)
{
	if (!p)
		return (0);
	if (OS)
		mac_key_press(keycode);
	else
		linux_key_press(keycode);
	return (1);
}