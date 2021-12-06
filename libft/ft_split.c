/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:07:38 by arohmann          #+#    #+#             */
/*   Updated: 2021/06/27 12:45:25 by arohmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countc(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i + 1] == c)
			i++;
		if (s[i] == c)
			count++;
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		i;
	int		w[2];
	int		beg;

	beg = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	w[0] = ft_countc(s, c);
	w[1] = -1;
	res = malloc(sizeof(char *) * (w[0] + 1));
	if (res == NULL)
		return (NULL);
	while (w[0] > ++w[1])
	{
		while (s[i] == c)
			i++;
		beg = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		res[w[1]] = ft_substr(s, beg, i - beg);
	}
	res[w[1]] = NULL;
	return (res);
}
