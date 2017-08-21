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
}

static char	**read_input(void)
{
	int		b;
	char	*buff;
	char	**ret;

	ret = 0;
	buff = (char*)ft_memalloc(sizeof(char) * BUFFSIZE);
	b = read(0, buff, BUFFSIZE);
	if (b)
		ret = ft_msh_split(buff);
	ft_memdel((void**)&buff);
	return (ret);
}

int			main()
{
	char	**av;
	int		i = 0;

	av = 0;
	while (42)
	{
		ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
		if ((av = read_input()))
			mshell_cmds(av);
		while (av[i] != 0)
			ft_memdel((void**)&av[i++]);
		ft_memdel((void**)av);
	}
	return (0);
}
