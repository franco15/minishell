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

static int	ft_wordlen(char *s, int k)
{
	int	i;

	i = 0;
	while (s[k])
	{
		if (s[k] == 34)
			k++;
		else
		{
			k++;
			i++;
		}
	}
	return (i);
}

static int	ft_countwords(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != ' ')
			i++;
		while (*s && *s != ' ')
			s++;
		if (!s)
			return (i);
		s++;
	}
	return (i);
}

static void	del_nl(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (s[i] == '\n')
		s[i] = '\0';
}

static void	fill_arr(char **r, char *s)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < (ft_countwords(s)))
	{
		j = 0;
		r[i] = (char*)ft_memalloc(sizeof(char) * ft_wordlen(s, k) + 1);
		while (s[k] && s[k] == ' ')
			k++;
		s[k] == 34 ? k++ : 0;
		while (s[k] && s[k] != ' ' && s[k] != 34)
			r[i][j++] = s[k++];
		r[i][j] = '\0';
	}
	del_nl(r[i - 1]);
	// r[i] = 0;
}

char		**ft_msh_split(char *s)
{
	char	**r;

	if (!s)
		return (0);
	r = (char**)ft_memalloc(sizeof(char*) * ft_countwords(s) + 1);
	if (!r)
		return (0);
	fill_arr(r, s);
	return (r);
}
