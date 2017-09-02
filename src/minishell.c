/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:09:20 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/31 11:52:39 by coco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_exit(char **cmd, char **env)
{
	ft_arrdel((void**)cmd);
	ft_arrdel((void**)env);
	exit(1);
}

static void	msh_cmds(char *av, char **env)
{
	char	**cmd;

	cmd = ft_split_input(av);
	if (cmd[0] && !ft_strcmp(cmd[0], "cd"))
		ft_cooldown(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "env"))
		ft_env(ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "setenv"))
		ft_setenv(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "unsetenv"))
		ft_unsetenv(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "pwd"))
		ft_pwd(env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "exit"))
		ft_exit(cmd, env);
	else
		ft_exe(cmd, env);
	ft_arrdel((void**)cmd);
}

static char **read_input(void)
{
	char	buff[BUFFSIZE];

	ft_bzero(buff, BUFFSIZE);
	read(0, buff, BUFFSIZE);
	// if (ft_strchr(buff, ';'))
		return (ft_strsplit(buff, ';'));
	// return (ft_split_input(buff));
}

int		main(int ac, char **argv, char **env)
{
	int		i;
	char	**av;
	char	**ev;
	(void)ac;
	(void)argv;

	ev = create_env(env);
	while (42)
	{
		i = 0;
		ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
		// ft_printf("minishell\n->");
		av = read_input();
		if (!ft_arrlen((void**)av))
		{
			ft_arrdel((void**)av);
			continue ;
		}
		while (av[i])
			msh_cmds(av[i++], ev);
		ft_arrdel((void**)av);
	}
	ft_arrdel((void**)ev);
	return (0);
}
