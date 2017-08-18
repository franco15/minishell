/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:41:17 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 20:41:18 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	mshell_cmds(char **cmd)
{
	if (cmd[0] && !ft_strcmp(cmd[0], "exit"))
		ft_exit(cmd);
	if (cmd[0] && !ft_strcmp(cmd[0], "echo"))
		ft_echo(cmd);
	ft_arrdel((void**)cmd);
}

static char	**read_input(void)
{
	int		b;
	char	buff[BUFFSIZE];
	char	**ret;

	ret = 0;
	if ((b = read(0, buff, BUFFSIZE)))
		ret = ft_msh_split(buff);
	ft_bzero((void*)buff, BUFFSIZE);
	return (ret);
}

int			main()
{
	char	**av;

	while (42)
	{
		ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
		if ((av = read_input()))
			mshell_cmds(av);
	}
	return (0);
}
