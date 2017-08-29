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
	while (s[i] && s[i] != '"' && s[i] != ' ' && s[i] != '\n')
	{
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
	while (*s && *s == ' ')
		s++;
	while (*s)
	{
		if (*s != ' ' && *s != '\n')
			i++;
		while (*s && *s != ' ')
			s++;
		while (*s && *s == ' ')
			s++;
	}
	return (i);
}

char	**ft_split_input(char *s)
{
	int		i;
	int		j;
	char	**ret;

	i = count_words(s);
	ret = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	j = 0;
	while (j < i)
	{
		while (*s && *s == ' ')
			s++;
		ret[j] = get_word(&*s);
		while (*s && *s != ' ')
			s++;
		j++;
	}
	return (ret);
}
