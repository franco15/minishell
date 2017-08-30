/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:09:46 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/28 17:09:47 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(char *s, char **env)
{
	int	i;

	i = get_env(s, env);
	if (i < 0)
		return ;
	ft_printf("%s ", &env[i][ft_strlen(s)]);
}

void		ft_echo(char **av, int ac, char **env)
{
	int	i;
	int	n;

	i = 0;
	n = -1;
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "-n"))
			n = 1;
		if (!ft_strcmp(av[1], "-n") && ac < 3)
			return ;
		while (av[++i])
		{
			if (n == 1)
			{
				n = 0;
				continue ;
			}
			av[i][0] == '$' ? print_env(av[i], env) : ft_printf("%s ", av[i]);
		}
	}
	if (++n == 0)
		ft_printf("\n");
}
