/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:41:25 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 20:41:27 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "minilibft.h"
# include <sys/wait.h>
# include <limits.h>

# define BUFFSIZE 50

/*
** echo.c
*/
void	ft_echo(char **s);

/*
** exit.c
*/
void	ft_exit(char **s);

/*
** minishell.c
*/
int		main();

/*
** utils.c
*/
int		is_cmd(char *cmd);

#endif
