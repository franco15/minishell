/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 22:03:51 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 22:03:52 by lfranco-         ###   ########.fr       */
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

void		ft_unsetenv(char **s, int ac, char **env)
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

void		repalce_env(char **env, int e, char *val)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp2 = 0;
	while (env[e][i] != '=')
		i++;
	tmp = ft_strndup(env[e], ++i);
	ft_memdel((void**)&env[e]);
	if (!val)
		env[e] = ft_strdup(tmp);
	else
	{
		tmp2 = ft_strjoin(tmp, val);
		env[e] = ft_strdup(tmp2);
		ft_memdel((void**)&tmp2);
	}
	ft_memdel((void**)&tmp);
}

void		ft_setenv(char **s, int ac, char **env)
{
	int		i;
	int		e;
	char	*tmp;

	i = 0;
	tmp = 0;
	e = 0;
	if (ac == 1)
		ft_env(ac, env);
	else if (ac == 2)
	{
		if ((e = get_env(s[1], env)) != -1)
			return (repalce_env(env, e, 0));
		i = ft_arrlen((void**)env);
		env[i] = ft_strjoin(s[1], "=");
	}
	else if (ac == 3)
	{
		if ((e = get_env(s[1], env)) != -1)
			return (repalce_env(env, e, s[2]));
		i = ft_arrlen((void**)env);
		tmp = ft_strjoin(s[1], "=");
		env[i] = ft_strjoin(tmp, s[2]);
		ft_memdel((void**)&tmp);
	}
}

void		ft_env(int ac, char **env)
{
	int	i;

	i = 0;
	if (ac == 1)
		while (env[i])
			ft_printf("%s\n", env[i++]);
}
