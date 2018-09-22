/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:53:23 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/14 13:53:26 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_H
# define OS_H

# if defined(__APPLE__) && defined(__MACH__)
#  define OS 1
# elif defined(__linux__)
#  define OS 0
# endif

#endif
