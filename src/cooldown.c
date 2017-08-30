/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cooldown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 19:18:40 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 19:18:41 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_chdir(char **av, char **env)
{
	int		e;
	int		cd;
	char	*path;
	char	*tmp;

	if (av[1][ft_strlen(av[1])] != '/')
	{
		tmp = ft_strjoin("/", av[1]);
		free(av[1]);
		av[1] = ft_strdup(tmp);
		free(tmp);
	}
	e = get_env("$PWD", env);
	tmp = ft_strdup(av[1]);
	path = ft_strjoin(&env[e][4], tmp);
	printf("path: %s\n", path);
	cd = chdir(path);
	if (cd == 0)
		update_pwd(env, path);
	else
		ft_printf("ded: %s\n", strerror(errno));
	ft_memdel((void**)&tmp);
	ft_memdel((void**)&path);
}

static void	go_back(char **env)
{
	int		e;
	int		cd;
	char	*path;

	e = get_env("$OLDPWD", env);
	path = ft_strdup(&env[e][7]);
	cd = chdir(path);
	if (cd == 0)
	{
		ft_printf("%s\n", path);
		update_pwd(env, path);
	}
	else
		ft_printf("ded: %s\n", strerror(errno));
	ft_memdel((void**)&path);
}

static void	go_home(char **env)
{
	int		e;
	int		cooldown;
	char	*path;

	e = get_env("$HOME", env);
	path = ft_strdup(&env[e][5]);
	cooldown = chdir(path);
	if (cooldown == 0)
		update_pwd(env, path);
	else
		ft_printf("ded: %s\n", strerror(errno));
	ft_memdel((void**)&path);
}

void		ft_cooldown(char **s, int ac, char **env)
{
	(void)s;
	if (ac == 1)
		go_home(env);
	else if (ac == 2 && !ft_strcmp(s[1], "-"))
		go_back(env);
	else if (ac == 2)
		ft_chdir(s, env);
}
