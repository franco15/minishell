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
	int		i;
//	int		ded;   to exit after all cmds (if they exist) are done

	i = -1;
	while (cmd[++i])
	{
		if (!ft_strcmp(cmd[i], "exit\n"))
			exit(1);
		if (!ft_strcmp(cmd[i], "echo\n") || !ft_strcmp(cmd[0], "echo"))
			cmd[i + 1] ? ft_printf("%s\n", cmd[++i]) : ft_printf("\n");
	}
}

int			main()
{
	int		b;
	pid_t	f;
	char	buff[BUFFSIZE];
	char	**av;

	while (42)
	{
		f = fork();
		if (f != 0)
		{
			ft_printfcolor("%s\n%s ", "minishell", 32, "->", 93);
			wait(&f);
		}
		else
		{
			if ((b = read(0, buff, BUFFSIZE)))
			{
				av = ft_strsplit(buff, ' ');
				// ft_printf("%s", av[0]);
				mshell_cmds(av);
				ft_bzero((void*)buff, BUFFSIZE);
			}
		}
		ft_arrdel((void**)av);

	}
	return (0);
}
