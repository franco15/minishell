/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 22:03:57 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 22:03:58 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(char **s, int ac, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = 0;
	if (ac == 1)
		ft_env(s, ac, env);
	else if (ac == 2)
	{
		i = ft_arrlen((void**)env);
		env[i] = ft_strjoin(s[1], "=");
	}
	else if (ac == 3)
	{
		i = ft_arrlen((void**)env);
		tmp = ft_strjoin(s[1], "=");
		env[i] = ft_strjoin(tmp, s[2]);
		ft_memdel((void**)&tmp);
	}
}
