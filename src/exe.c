/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coco <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 11:58:14 by coco              #+#    #+#             */
/*   Updated: 2017/08/31 11:58:15 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	run_exe(char *exe, char **av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(exe, av, env) != -1)
			return (1);
	}
	else if (pid < 0)
		ft_printf("Error Forking\n");
	wait(0);
	return (0);
}

static int	run_something(char **bins, char **av, char **env)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = -1;
	if (bins == 0)
		return (0);
	while (bins[++i])
	{
		tmp = ft_strjoin(bins[i], "/");
		tmp2 = ft_strjoin(tmp, av[0]);
		if (access(tmp2, X_OK) == 0)
		{
			run_exe(tmp2, av, env);
			ft_memdel((void**)&tmp);
			ft_memdel((void**)&tmp2);
			return (1);
		}
		ft_memdel((void**)&tmp);
		ft_memdel((void**)&tmp2);
	}
	return (0);
}

void		ft_exe(char **av, char **env)
{
	int			e;
	char		**bins;
	char		*tmp;
	struct stat	st;

	tmp = 0;
	e = get_env("$PATH", env);
	bins = e != -1 ? ft_strsplit(&env[get_env("$PATH", env)][5], ':') : 0;
	if (lstat(av[0], &st) != -1)
	{
		if (!ft_strncmp(av[0], "./", 2))
		{
			run_exe((tmp = ft_strdup(&av[0][2])), av, env);
			ft_memdel((void**)&tmp);
		}
		else if (access(av[0], X_OK) == 0)
			run_exe(av[0], av, env);
	}
	else if (run_something(bins, av, env) == 0)
		ft_printf("minishell: command not found: %s\n", av[0]);
	if (bins != 0)
		ft_arrdel((void**)bins);
}
