/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:23:59 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/24 11:20:13 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**pedri_is_free(char **p, int j)
{
	while (j >= 0)
		free(p[j--]);
	free(p);
	return (NULL);
}

static int	wd_nbr(char const *str, char sep)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != sep)
			n++;
		if (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static int	wd_len(char const *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		lw;
	int		j;
	char	**p;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	p = malloc(sizeof(char *) * (wd_nbr(s, c) + 1));
	if (!p)
		return (NULL);
	while (++j < wd_nbr(s, c))
	{
		while (s[i] == c)
			i++;
		lw = wd_len(s + i, c);
		p[j] = ft_substr(s, i, lw);
		if (!p)
			return (pedri_is_free(p, j));
		i += lw;
	}
	p[j] = NULL;
	return (p);
}
