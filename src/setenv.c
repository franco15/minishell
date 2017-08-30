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

static void	new_env(char **s, char **env)
{
	(void)s;
	(void)env;
}

static void	no_value(char *s, char **env)
{
	(void)s;
	(void)env;
	// int		i;
	// int		j;
	// char	*t;
	// char	**tmp;
	// char	**tmp2;
	//
	// i = ft_arrlen((void**)env) + 1;
	// tmp = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	// j = -1;
	// while (env[++j])
	// 	tmp[j] = ft_strdup(env[j]);
	// t = ft_strjoin(s, "=");
	// tmp[j] = ft_strdup(t);
	// ft_memdel((void**)&t);
	// // free(env);
	// tmp2 = env;
	// env = tmp;
	// tmp = tmp2;
	// ft_arrdel((void**)tmp);
}

void	ft_setenv(char **s, int ac, char **env)
{
	if (ac == 1)
		ft_env(s, ac, env);
	else if (ac == 2)
		no_value(s[1], env);
	else if (ac == 3)
		new_env(s, env);
}
