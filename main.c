/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:29:32 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 20:41:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"
#include <stdlib.h>

static int	ft_error(void)
{
	ft_putstr("Error\n");
	return (CHECK_ERR);
}
// tout doux :
// - Gestion des paramêtres avec des chaines de plsrs nb au milieu des args
// - algo avec les chunks

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

int main(int ac, char **av)
{
	char	**tab;
	int		verbose;

	if (ac == 1)
		return (ft_error());
	verbose = (ft_strcmp("-v", av[1]) == 0);
	if (ac == 1 + verbose)
		return (ft_error());
	if (ac >= 2 + verbose)
	{
		tab = ft_attribute_params(av, verbose);
		if (!tab || !tab[0])
		{
			ft_free_tab(tab);
			return (ft_error());
		}
		ft_push_swap(tab, verbose);
		ft_free_tab(tab);
	}
	return (0);
}