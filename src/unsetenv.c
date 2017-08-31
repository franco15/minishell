/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 22:04:02 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 22:04:04 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_env(char **env, int e)
{
	free(env[e]);
	while (env[e + 1])
	{
		env[e] = env[e + 1];
		e++;
	}
	env[e] = 0;
}

void	ft_unsetenv(char **s, int ac, char **env)
{
	int		i;
	int		e;

	i = 0;
	e = 0;
	if (ac == 1)
	{
		ft_printf("unsetenv: Too few arguments.\n");
		return ;
	}
	while (s[++i])
	{
		e = 0;
		while (env[e])
		{
			if (!ft_strncmp(s[i], env[e], ft_strlen(s[i])))
			{
				remove_env(env, e);
				break ;
			}
			e++;
		}
	}
}
