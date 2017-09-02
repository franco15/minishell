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

char	*check_if_goin_to_parent_dir(char *p)
{
	int		i;
	char	*ret;

	i = ft_strlen(p);
	ret = ft_strchr(p, '.');
	if (ft_strncmp(ret, "..", 2))
		return (ft_strdup(p));
	i -= 3;
	while (p[--i] && p[i] != '/')
		;
	ret = ft_strndup(p, i);
	return (ret);
}

static void	cooldown_env(char *s, char **env)
{
	int		e;
	int		cd;
	char	*path;

	e = get_env(s, env);
	cd = 0;
	while (env[e][cd] && env[e][cd] != '=')
		cd++;
	path = ft_strdup(&env[e][++cd]);
	cd = chdir(path);
	if (cd == 0)
		update_pwd(env, path);
	else
		ft_printf("cd: no such file or directory: %s\n", path);
	ft_memdel((void**)&path);
}

static void	ft_chdir(char *av, char **env)
{
	int		e;
	int		cd;
	char	*path;
	char	*tmp;

	tmp = 0;
	if (av[ft_strlen(av)] != '/' && av[0] != '/' && ft_strcmp(av, "/"))
		tmp = ft_strjoin("/", av);
	e = get_env("$PWD", env);
	tmp = tmp != 0 ? tmp : ft_strdup(av);
	if (av[0] == '~')
		path = ft_strjoin(&env[get_env("$HOME", env)][5], &av[1]);
	else if (!ft_strcmp(av, "/"))
		path = ft_strdup("/");
	else
		path = av[0] != '/' ? ft_strjoin(&env[e][4], tmp) : ft_strdup(av);
	cd = chdir(path);
	cd == 0 ? update_pwd(env, path) :
			ft_printf("cd: no such file or directory: %s\n", av);
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
		ft_printf("cd: no such file or directory: %s\n", path);
	ft_memdel((void**)&path);
}

void		ft_cooldown(char **s, int ac, char **env)
{
	int		e;
	int		cooldown;
	char	*path;

	e = 0;
	path = 0;
	cooldown = 0;
	if (ac == 1 || (ac == 2 && !ft_strcmp(s[1], "~")))
	{
		e = get_env("$HOME", env);
		path = ft_strdup(&env[e][5]);
		cooldown = chdir(path);
		if (cooldown == 0)
			update_pwd(env, path);
		else
			ft_printf("cd: no such file or directory: %s\n", path);
		ft_memdel((void**)&path);
	}
	else if (ac == 2 && !ft_strcmp(s[1], "-"))
		go_back(env);
	else if (ac == 2 && s[1][0] == '$')
		cooldown_env(s[1], env);
	else if (ac == 2)
		ft_chdir(s[1], env);
}
