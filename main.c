/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:29:32 by user42            #+#    #+#             */
/*   Updated: 2021/07/29 14:07:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

static int	ft_error(void)
{
	ft_putstr("Error\n");
	return (CHECK_ERR);
}
// tout doux :
// - Gestion des paramêtres avec des chaines de plsrs nb au milieu des args
// - optimize_move avec suppr des pa > pb / pb > pa
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
	if (ac == 2 + verbose)
	{
		//tab = ft_look_for_arg(ac, av, verbose);
		tab = ft_split(av[1 + verbose], ' ');
		if (!tab || !tab[0])
		{
			ft_free_tab(tab);
			return (ft_error());
		}
		ft_push_swap(tab, verbose);
		ft_free_tab(tab);
	}
	else
		ft_push_swap(av + (1 + verbose), verbose);
	return (0);
}