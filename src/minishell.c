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
	int		i = 0;

	if (cmd[0] && !ft_strncmp(cmd[0], "exit", 4))
		ft_exit(cmd);
	if (cmd[0] && !ft_strncmp(cmd[0], "echo", 4))
		ft_echo(cmd);
	while (cmd[i] != 0)
		ft_memdel((void**)&cmd[i++]);
	ft_memdel((void**)cmd);
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
		ret = ft_strsplit(buff, ' ');
	ft_memdel((void**)&buff);
	return (ret);
}

int			main()
{
	char	**av;

	av = 0;
	while (42)
	{
		ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
		av = read_input();
		if (!av)
			return (0);
		mshell_cmds(av);
	}
	return (0);
}
