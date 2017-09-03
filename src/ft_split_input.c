/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:23:05 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 17:23:07 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	word_len(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] == '"')
		i++;
	while (s[i] && s[i] != '"' && s[i] != ' ' && s[i] != '\t' &&
			s[i] != '\n')
	{
		if (s[i] == 39 && s[i + 1] == 92 && s[i + 2] == 99 && s[i + 3] == 39)
			return (i);
		i++;
		j++;
	}
	return (j);
}

static char	*get_word(char *s)
{
	int		i;
	char	*ret;

	i = word_len(s);
	while (*s && *s == '"')
		s++;
	ret = ft_strndup(s, i);
	return (ret);
}

static int	count_words(char *s)
{
	int	i;

	i = 0;
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			i++;
		while (*s && *s != ' ' && *s != '\t')
		{
			if (*s == 39 && *(s + 1) == 92 && *(s + 2) == 99 && *(s + 3) == 39)
				return (i);
			s++;
		}
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
	}
	return (i);
}

char		**ft_split_input(char *s)
{
	int		i;
	int		j;
	char	**ret;

	i = count_words(s);
	ret = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	j = 0;
	while (j < i)
	{
		while (*s && (*s == ' ' || *s == '\t'))
			s++;
		ret[j] = get_word(&*s);
		while (*s && *s != ' ' && *s != '\t')
			s++;
		j++;
	}
	return (ret);
}
