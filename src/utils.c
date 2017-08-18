/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 03:14:51 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/18 03:14:52 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_cmd(char *cmd)
{
	if (cmd)
	{
		if (!ft_strcmp(cmd, "cd"))
			return (1);
		if (!ft_strcmp(cmd, "env"))
			return (1);
		if (!ft_strcmp(cmd, "echo"))
			return (1);
		if (!ft_strcmp(cmd, "exit"))
			return (1);
		if (!ft_strcmp(cmd, "setenv"))
			return (1);
		if (!ft_strcmp(cmd, "unsetenv"))
			return (1);
	}
	return (0);
}
