/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:30:01 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 21:30:02 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

static int		ft_wordlen(char const *s, char c, int k)
{
	int	i;

	i = 0;
	while (s[k])
	{
		if (s[k] == c)
			k++;
		else
		{
			k++;
			i++;
		}
	}
	return (i);
}

static int		ft_countwords(char const *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s != c && *s)
			s++;
		if (!*s)
			return (i);
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**r;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	if (!(r = (char**)ft_memalloc(sizeof(char*) * ft_countwords(s, c) + 1)))
		return (0);
	while (i < (ft_countwords(s, c)))
	{
		j = 0;
		r[i] = (char*)ft_memalloc(sizeof(char) * ft_wordlen(s, c, k) + 1);
		while (s[k] == c && s[k] != '\0')
			k++;
		while (s[k] != c && s[k] != '\0')
			r[i][j++] = s[k++];
		r[i][j] = '\0';
		i++;
	}
	r[i] = 0;
	return (r);
}
