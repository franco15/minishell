/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:33:03 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 21:33:03 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_arrdel(void **arr)
{
	void	**tmp;

	tmp = arr;
	if (!arr)
		return ;
	while (*tmp)
	{
		free(*tmp);
		*tmp = 0;
		tmp++;
	}
	free(arr);
	arr = 0;
}

size_t	ft_arrlen(void **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_arrdup(char **s)
{
	int		i;
	int		j;
	char	**ret;

	i = ft_arrlen((void**)s);
	j = i;
	ret = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (j--)
	{
		ret[i] = ft_strdup(s[i]);
		i++;
	}
	return (ret);
}
