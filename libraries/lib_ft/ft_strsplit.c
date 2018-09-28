/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:00:55 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/28 13:29:23 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"

static size_t	count_splits(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
		i++;
	}
	return (i);
}

static size_t	split_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**splits;

	if (!s)
		return (NULL);
	i = 0;
	if (!(splits = (char**)ft_memalloc(sizeof(splits) *
							(count_splits(s, c) + 1))))
		return (NULL);
	while (*s == c)
		s++;
	while (*s)
	{
		len = split_len(s, c);
		if (!(splits[i] = ft_strnew(len)))
			return (NULL);
		ft_strncpy(splits[i++], s, len);
		while (*s && *s != c)
			s++;
		while (*s == c)
			s++;
	}
	return (splits);
}

// char	**ft_makearr(char **r, char const *s, char c, int size)
// {
// 	int		a;
// 	int		i;

// 	if (!r)
// 		return (NULL);
// 	a = 0;
// 	while (*s != '\0' && a < size)
// 	{
// 		if (*s != c)
// 		{
// 			i = 0;
// 			while (s[i] != c && s[i] != '\0')
// 				i++;
// 			r[a++] = ft_strsub(s, 0, i);
// 			s = s + i;
// 		}
// 		s++;
// 	}
// 	r[a] = NULL;
// 	return (r);
// }

// int		ft_wrdcnt(char const *s, char c)
// {
// 	int		i;
// 	char	*w;

// 	i = 0;
// 	w = (char *)s;
// 	if (w[0] != c)
// 		i++;
// 	w = (ft_strchr(s, c));
// 	while (w != 0)
// 	{
// 		if (w[1] != c && w[1] != '\0')
// 			i++;
// 		w = ft_strchr(w + 1, c);
// 	}
// 	return (i);
// }

// char	**ft_strsplit(char const *s, char c)
// {
// 	int		size;
// 	char	**ret;

// 	if (!s)
// 		return (NULL);
// 	size = ft_wrdcnt(s, c);
// 	ret = (char **)ft_memalloc(sizeof(char *) * size + 1);
// 	if (!ret)
// 		return (NULL);
// 	ret = ft_makearr(ret, s, c, size);
// 	if (!ret)
// 		return (NULL);
// 	return (ret);
// }
