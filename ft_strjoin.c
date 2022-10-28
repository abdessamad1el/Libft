/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-all <abel-all@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:07:34 by abel-all          #+#    #+#             */
/*   Updated: 2022/10/24 10:27:10 by abel-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	size_t	k;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	k = 0;
	p = (char *)malloc(j + 1);
	if (!p)
		return (NULL);
	while (s1[k])
		p[i++] = s1[k++];
	k = 0;
	while (s2[k])
		p[i++] = s2[k++];
	p[i] = '\0';
	return (p);
}
