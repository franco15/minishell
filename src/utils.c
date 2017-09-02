/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 03:14:51 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/18 03:14:52 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int		is_cmd(char *cmd)
// {
// 	if (cmd)
// 	{
// 		if (!ft_strcmp(cmd, "cd"))
// 			return (1);
// 		if (!ft_strcmp(cmd, "env"))
// 			return (1);
// 		if (!ft_strcmp(cmd, "echo"))
// 			return (1);
// 		if (!ft_strcmp(cmd, "exit"))
// 			return (1);
// 		if (!ft_strcmp(cmd, "setenv"))
// 			return (1);
// 		if (!ft_strcmp(cmd, "unsetenv"))
// 			return (1);
// 	}
// 	return (0);
// }

int		get_env(char *s, char **env)
{
	int	i;
	int	j;
	char	*tmp;

	i = 0;
	j = ft_strlen(&s[1]);
	tmp = ft_strnew(j + 1);
	tmp = ft_strncpy(tmp, &s[1], j);
	tmp[j] = '=';
	tmp[j + 1] = '\0';
	while (env[i])
	{
		if (!ft_strncmp(tmp, env[i], j + 1))
		{
			ft_memdel((void**)&tmp);
			return (i);
		}
		i++;
	}
	ft_memdel((void**)&tmp);
	return (-1);
}

void	ft_pwd(char **env)
{
	int		e;
	char	*pwd;

	e = get_env("$PWD", env);
	pwd = ft_strdup(&env[e][4]);
	ft_printf("%s\n", pwd);
	ft_memdel((void**)&pwd);
}

void	update_pwd(char **env, char *np)
{
	int		i;
	int		j;
	char	*t;
	char	*npp;

	npp = ft_strchr(np, '.') ? check_if_goin_to_parent_dir(np) : ft_strdup(np);
	i = get_env("$OLDPWD", env);
	free(env[i]);
	j = get_env("$PWD", env);
	t = ft_strdup(env[j]);
	env[i] = ft_strjoin("OLD", t);
	free(env[j]);
	ft_memdel((void**)&t);
	env[j] = ft_strjoin("PWD=", npp);
	ft_memdel((void**)&npp);
}

char	**create_env(char **env)
{
	int		i;
	char	**ret;

	i = 0;
	ret = (char**)ft_memalloc(sizeof(char*) * BUFFSIZE);
	while (env[i])
	{
		ret[i] = ft_strdup(env[i]);
		i++;
	}
	return (ret);
}
