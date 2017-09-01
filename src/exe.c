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

static void	run_bin(char **av, char **env)
{
	(void)av;
	(void)env;
	printf("smn 'corriendo bin'\n");
}

static void	run_exe(char *exe, char **av, char **env)
{
	(void)av;
	(void)env;
	(void)exe;
	printf("smn 'corriendo exe'\n");
}

static int	check_if_bin(char *bin, char **bins)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(bin) - 1;
	while (bin[j] != '/')
		--j;
	--j;
	while (bins[i])
		if (!ft_strncmp(bins[i++], bin, j))
			return (1);
	return (0);
}

void	ft_exe(char **av, char **env)
{
	int		e;
	char	**bins;
	char	*tmp;
	struct stat	st;

	tmp = 0;
	e = get_env("$PATH", env);
	if (e == -1)
		return ;
	bins = ft_strsplit(&env[get_env("$PATH", env)][5], ':');
	if (lstat(av[0], &st) != -1)
	{
		if (!ft_strncmp(av[0], "./", 2))
			run_exe((tmp = ft_strdup(av[2])), av, env);
		else if (check_if_bin(av[0], bins))
			run_bin(av, env);
	}
	else
		ft_printf("minishell: command not found: %s\n", av[0]);
	ft_arrdel((void**)bins);
}
