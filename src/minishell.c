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
	else if (cmd[0] && !ft_strcmp(cmd[0], "env"))
		ft_env(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "setenv"))
		ft_setenv(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "unsetenv"))
		ft_unsetenv(cmd, ft_arrlen((void**)cmd), env);
	else if (cmd[0] && !ft_strcmp(cmd[0], "pwd"))
		ft_pwd(env);
	else
		ft_printf("minishell: command not found: %s\n", cmd[0]);
}

static char **read_input(char **ev)
{
	char	buff[BUFFSIZE];

	ft_bzero(buff, BUFFSIZE);
	read(0, buff, BUFFSIZE);
	if (!ft_strncmp(buff, "exit", 4))
	{
		ft_arrdel((void**)ev);
		exit(1);
	}
	return (ft_split_input(buff));
}

int		main(int ac, char **argv, char **env)
{
	char	**av;
	char	**ev;
	(void)ac;
	(void)argv;

	ev = create_env(env);
	while (42)
	{
		ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
		// ft_printf("minishell\n->");
		av = read_input(ev);
		msh_cmds(av, ev);
		ft_arrdel((void**)av);
	}
	ft_arrdel((void**)ev);
	return (0);
}
