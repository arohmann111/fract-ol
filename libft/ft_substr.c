/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:22:21 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/24 13:01:17 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dst;

	if (s == NULL)
		return (NULL);
	dst = (char *)malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*dst = '\0';
		return (dst);
	}
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
