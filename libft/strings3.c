/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:30:01 by lfranco-          #+#    #+#             */
/*   Updated: 2017/08/17 21:30:02 by lfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibft.h"

char	*ft_strndup(const char *s1, size_t l)
{
	char	*dup;

	if ((dup = ft_strnew(l)))
		return (ft_strncpy(dup, s1, l));
	return (0);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*p;
	size_t	l;

	l = ft_strlen(src);
	p = dst;
	if (len > l)
	{
		while (*src)
		{
			*p++ = *src++;
			len--;
		}
		while (len-- > 0)
			*p++ = '\0';
	}
	else
		while (len-- > 0)
			*p++ = *src++;
	return (dst);
}
