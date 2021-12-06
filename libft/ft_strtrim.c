/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:57:47 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/25 18:43:32 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		start;
	int		end;

	start = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] != '\0')
	{
		if (ft_isinset(set, s1[start]) == 0)
			break ;
		start++;
	}
	end = (ft_strlen(s1) - 1);
	while (start < end)
	{
		if (ft_isinset(set, s1[end]) == 0)
			break ;
		end--;
	}
	dst = ft_substr(s1, start, (end - start + 1));
	if (dst != NULL)
		dst[ft_strlen(dst)] = '\0';
	return (dst);
}
