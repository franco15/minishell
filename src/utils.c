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

int		is_cmd(char *cmd)
{
	if (cmd)
	{
		if (!ft_strcmp(cmd, "cd"))
			return (1);
		if (!ft_strcmp(cmd, "env"))
			return (1);
		if (!ft_strcmp(cmd, "echo"))
			return (1);
		if (!ft_strcmp(cmd, "exit"))
			return (1);
		if (!ft_strcmp(cmd, "setenv"))
			return (1);
		if (!ft_strcmp(cmd, "unsetenv"))
			return (1);
	}
	return (0);
}

void	ft_avdel(char **av)
{
	char	**tmp;

	tmp = av;
	if (!av)
		return ;
	while (*tmp)
	{
		free(*tmp);
		*tmp = 0;
		tmp++;
	}
	free(av);
	av = 0;
}

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
