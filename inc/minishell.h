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
# include <string.h>
# include <unistd.h>
# include "../libft/minilibft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <limits.h>

# define BUFFSIZE 1000

/*
** cd.c
*/
void	ft_cooldown(char **av, int ac, char **env);
char	*check_if_goin_to_parent_dir(char *p);

/*
** echo.c
*/
void	ft_echo(char **s, int ac, char **env);

/*
** env.c
*/
void	ft_env(int ac, char **env);
void	ft_setenv(char **av, int ac, char **env);
void	ft_unsetenv(char **av, int ac, char **env);

/*
** exe.c
*/
void	ft_exe(char **av, char **env);

/*
** ft_split_input.c
*/
char	**ft_split_input(char *s);

/*
** minishell.c
*/
int		main(int ac, char **argv, char **env);

/*
** utils.c
*/
int		get_env(char *s, char **env);
void	ft_pwd(char **env);
void	update_pwd(char **env, char *np);
char	**create_env(char **env);
char	*ft_getcwd(void);

#endif
