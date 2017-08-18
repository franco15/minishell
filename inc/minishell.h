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

# define BUFFSIZE 262144

/*
** minishell.c
*/
int	main();

/*
** echo.c
*/
void	ft_echo(char *s);

#endif
