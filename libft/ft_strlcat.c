/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:17:50 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/27 16:39:30 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat( char *dest, const char *src, size_t size )
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	output;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (dlen >= size)
		output = (size + slen);
	else
		output = (dlen + slen);
	while (src[i] != '\0' && dlen + 1 < size)
	{
		dest[dlen] = src[i];
		i++;
		dlen++;
	}
	if (size > 0 && dlen <= size)
		dest[dlen] = '\0';
	return (output);
}
