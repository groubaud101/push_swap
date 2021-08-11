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
#include "ft_push_swap.h"

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

static char	**ft_split_pusw(char const *s, char **tab, int *j)
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

static int	ft_count_words(char const *s, char c)
{
	int	ct;

	ct = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			ct++;
		while (*s && *s != c)
			s++;
	}
	return (ct);
}

char	**ft_attribute_params(char **av, int verbose)
{
	int		i;
	int		j;
	int		nb_wrd;
	char	**tab;

	i = verbose + 1;
	nb_wrd = 0;
	while (av[i])
	{
		nb_wrd += ft_count_words(av[i], ' ');
		i++;
	}
	tab = (char **)malloc(sizeof(*tab) * (nb_wrd + 1));
	if (!tab)
		return (CHECK_ERR);
	i = verbose + 1;
	j = 0;
	while (av[i])
	{
		tab = ft_split_pusw(av[i++], tab, &j);
		if (!tab)
			return (CHECK_ERR);
	}
	return (tab);
}
