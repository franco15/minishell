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

void		ft_echo(char **s, char **env)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (s[1])
	{
		if (!ft_strcmp(s[1], "-n"))
			n = 1;
		while (s[++i])
		{
			if (s[i][0] == '$')
				print_env(s[i], env);
			else
				ft_printf("%s ", s[i]);
		}
	}
	if (n == 0)
		ft_printf("\n");
}
