/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtra.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 04:12:03 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/18 04:12:04 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

int		ft_isallupper(char *s)
{
	while (*s)
	{
		if (*s < 'A' || *s > 'Z')
			return (0);
		s++;
	}
	return (1);
}

int		ft_countwords(char const *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
			i++;
		while (*s && *s != c)
			s++;
		if (!*s)
			return (i);
		s++;
	}
	return (i);
}

int		ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		else
		{
			s++;
			i++;
		}
	}
	return (i);
}
