/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:54:00 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 15:13:52 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mac_key_press(int keycode, t_param *p)
{
	if (keycode == 53)
		exit_program(p);
}

void	linux_key_press(int keycode, t_param *p)
{
	if (keycode == 65307)
		exit_program(p);
}

int		key_press(int keycode, t_param *p)
{
	if (!p)
		return (0);
	if (OS)
		mac_key_press(keycode, p);
	else
		linux_key_press(keycode, p);
	return (1);
}
