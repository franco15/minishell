/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:33:03 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 21:33:03 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

void	ft_arrdel(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i++] = 0;
	}
	free(arr);
	arr = 0;
}
size_t	ft_arrlen(void **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
