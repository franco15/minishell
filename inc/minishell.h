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

# define BUFFSIZE 100

/*
** cd.c
*/
void	ft_cd(char **s);

/*
** echo.c
*/
void	ft_echo(char **s, char **env);

/*
** env.c
*/
void	ft_env(char **s);

/*
** exit.c
*/
void	ft_exit(char **s);

/*
** ft_split_input.c
*/
char	**ft_split_input(char *s);

/*
** minishell.c
*/
int		main(int ac, char **argv, char **env);

/*
** setenv.c
*/
void	ft_setenv(char **s);

/*
** unsetenv.c
*/
void	ft_unsetenv(char **s);

/*
** utils.c
*/
int		is_cmd(char *cmd);
void	ft_avdel(char **av);
int		get_env(char *s, char **env);

#endif
