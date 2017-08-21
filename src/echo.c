/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:51:13 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 21:51:14 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_env(char *s)
{
	char	*buff;

	buff = 0;
	if (!ft_isallupper(&s[1]))
		return ;
	if ((buff = getcwd(NULL, 0)))
		ft_printf("buff: %s", buff);
	free(buff);
}

void	ft_echo(char **s)
{
	int		i;

	i = 1;
	if (!s[i])
	{
		ft_printf("\n");
		return ;
	}
	while (s[i])
	{
		if (s[i] && s[i][0] == '$')
		{
			echo_env(s[i]);
		}
		else if (s[i])
			ft_printf("%s ", s[i]);
		i++;
	}
	ft_printf("\n");
}
