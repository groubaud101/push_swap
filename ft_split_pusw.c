/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:31 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:31 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_special_strlen(char const *s, int start, char end)
{
	int	index;

	index = 0;
	while (s[index + start] && s[index + start] != end)
		index++;
	return (index);
}

static char	**ft_free_tab(char **tab, int len)
{
	while (len)
		free(tab[--len]);
	free(tab);
	return (NULL);
}

char	**ft_split_pusw(char const *s, char **tab, int *j)
{
	int		len;

	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (*s)
		{
			len = ft_special_strlen(s, 0, ' ');
			tab[*j] = (char *)ft_calloc(sizeof(*tab), len + 1);
			if (!(tab[*j]))
				return (ft_free_tab(tab, *j));
			ft_strlcpy(tab[*j], s, len + 1);
			s = s + len;
			*j = *j + 1;
		}
	}
	tab[*j] = NULL;
	return (tab);
}
