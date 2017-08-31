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

static void	run_path_question_mark(char **av, char **env)
{
	(void)av;
	(void)env;
	// int		i;
	// char	**p;
	// char	*exe;
	//
	// i = 0;
	// p = ft_strsplit(env[get_env("$PATH", env)], ':');
	// while (p[i])
	// {
	// 	exe = check if is legit;
	// 	if (exe != 0)
	// 	{
	// 		run_exe();
	// 		ft_arrdel((void**)p);
	// 		return ;
	// 	}
	// 	else
	// 		i++;
	// }
	// ft_arrdel((void**)p);
	printf("smn 'corriendo bin'\n");
}

static void	run_exe(char **av)
{
	(void)av;
	printf("smn 'corriendo exe'\n");
}

void	ft_exe(char **av, char **env)
{
	int		e;
	struct stat	st;

	e = 0;
	if (lstat(av[0], &st) == 0)
	{
		run_exe(av);
		return ;
	}
	e = get_env("$PATH", env);
	if (e != -1)
		run_path_question_mark(av, env);
	else
		ft_printf("minishell: command not found: %s\n", av[0]);
}
