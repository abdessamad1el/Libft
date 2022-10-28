/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:49:34 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/22 15:29:11 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checktrim(char const s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	is;
	size_t	ie;
	size_t	l;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	is = 0;
	ie = ft_strlen(s1) - 1;
	while (s1[is] && (checktrim(s1[is], set) == 1))
		is++;
	while (s1[ie] && (checktrim(s1[ie], set) == 1) && is < ie)
		ie--;
	l = ie - is + 1;
	p = ft_substr(s1, is, l);
	return (p);
}
