/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 10:06:06 by shillebr          #+#    #+#             */
/*   Updated: 2018/08/30 14:13:46 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

// r,g,b values are from 0 to 1
// h = [0,360], s = [0,1], v = [0,1]
//		if s == 0, then h = -1 (undefined)

double		get_max(t_vec3 rgb)
{
	if (rgb.x >= rgb.y && rgb.x >= rgb.z)
		return (rgb.x);
	else if (rgb.y >= rgb.x && rgb.y >= rgb.z)
		return (rgb.y);
	else if (rgb.z >= rgb.x && rgb.z >= rgb.y)
		return (rgb.z);
	else
		return (-1);
}

double		get_min(t_vec3 rgb)
{
	if (rgb.x <= rgb.y && rgb.x <= rgb.z)
		return (rgb.x);
	else if (rgb.y <= rgb.x && rgb.y <= rgb.z)
		return (rgb.y);
	else if (rgb.z <= rgb.x && rgb.z <= rgb.y)
		return (rgb.z);
	else
		return (-1);
}

t_vec3		rgb_to_hsv(t_vec3 rgb)
{
	double	min;
	double	max;
	double	delta;
	t_vec3	hsv;

	min = get_min(rgb);
	max = get_max(rgb);
	hsv.z = max; //v
	delta = max - min;
	if (max != 0)
		hsv.y = delta / max;	//s
	else
	{
		//r = g = b = 0		s = 0, v is undefined
		hsv.y = 0;
		hsv.x = -1;
		return ; 
	}
	if (rgb.x == max)
		hsv.x = (rgb.y - rgb.z) / delta;
}

void RGBtoHSV( float r, float g, float b, float *h, float *s, float *v )
{
	float min, max, delta;
	min = MIN( r, g, b );
	max = MAX( r, g, b );
	*v = max;				// v
	delta = max - min;
	if( max != 0 )
		*s = delta / max;		// s
	else {
		// r = g = b = 0		// s = 0, v is undefined
		*s = 0;
		*h = -1;
		return;
	}
	if( r == max )
		*h = ( g - b ) / delta;		// between yellow & magenta
	else if( g == max )
		*h = 2 + ( b - r ) / delta;	// between cyan & yellow
	else
		*h = 4 + ( r - g ) / delta;	// between magenta & cyan
	*h *= 60;				// degrees
	if( *h < 0 )
		*h += 360;
}
void HSVtoRGB( float *r, float *g, float *b, float h, float s, float v )
{
	int i;
	float f, p, q, t;
	if( s == 0 ) {
		// achromatic (grey)
		*r = *g = *b = v;
		return;
	}
	h /= 60;			// sector 0 to 5
	i = floor( h );
	f = h - i;			// factorial part of h
	p = v * ( 1 - s );
	q = v * ( 1 - s * f );
	t = v * ( 1 - s * ( 1 - f ) );
	switch( i ) {
		case 0:
			*r = v;
			*g = t;
			*b = p;
			break;
		case 1:
			*r = q;
			*g = v;
			*b = p;
			break;
		case 2:
			*r = p;
			*g = v;
			*b = t;
			break;
		case 3:
			*r = p;
			*g = q;
			*b = v;
			break;
		case 4:
			*r = t;
			*g = p;
			*b = v;
			break;
		default:		// case 5:
			*r = v;
			*g = p;
			*b = q;
			break;
	}
}