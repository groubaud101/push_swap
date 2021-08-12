/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:29:32 by user42            #+#    #+#             */
/*   Updated: 2021/08/11 20:51:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"
#include <stdlib.h>

// tout doux :
// - algo avec les chunks

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
			ft_error();
		else
			ft_push_swap(tab, verbose);
		if (tab)
			ft_free_tab(tab);
	}
	return (0);
}