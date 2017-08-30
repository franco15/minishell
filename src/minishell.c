/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:09:20 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 17:09:22 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_cmds(char **cmd, char **env)
{
	if (cmd[0] && !ft_strcmp(cmd[0], "cd"))
		ft_cooldown(cmd, ft_arrlen((void**)cmd), env);
	if (cmd[0] && !ft_strcmp(cmd[0], "env"))
		ft_env(cmd, ft_arrlen((void**)cmd), env);
	if (cmd[0] && !ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, ft_arrlen((void**)cmd), env);
	if (cmd[0] && !ft_strcmp(cmd[0], "setenv"))
		ft_setenv(cmd, ft_arrlen((void**)cmd));
	if (cmd[0] && !ft_strcmp(cmd[0], "unsetenv"))
		ft_unsetenv(cmd, ft_arrlen((void**)cmd));
	if (cmd[0] && !ft_strcmp(cmd[0], "pwd"))
		ft_pwd(env);
}

static char **read_input(char **ev)
{
	char	buff[BUFFSIZE];

	ft_bzero(buff, BUFFSIZE);
	read(0, buff, BUFFSIZE);
	if (!ft_strncmp(buff, "exit", 4))
	{
		ft_avdel(ev);
		exit(1);
	}
	return (ft_split_input(buff));
}

int		main(int ac, char **argv, char **env)
{
	int 	i;
	char	**av;
	char	**ev;
	(void)ac;
	(void)argv;

	ev = ft_arrdup(env);
	while (42)
	{
		i = -1;
		ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
		av = read_input(ev);
		msh_cmds(av, ev);
		ft_avdel(av);
	}
	ft_avdel(ev);
	return (0);
}
