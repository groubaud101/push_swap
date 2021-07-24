/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/25 00:39:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

int	ft_check_error(char **tab)
{
	int	i;
	int sign;
	int	max;

	if (tab == NULL)
		return (CHECK_ERR);
	while (*tab)
	{
		i = 0;
		sign = ((*tab)[i] == '-' || (*tab)[i] == '+');
		i += sign;
		max = 10 + sign;
		while ((*tab)[i])
		{
			if (ft_isdigit((*tab)[i]) == 0 || (i >= max))
				return (CHECK_ERR);
			i++;
		}
		tab++;
	}
	return (CHECK_OK);
}

static t_pusw	ft_init_pusw(t_pusw ptr, int verbose)
{
	ptr.verbose = verbose;
	ptr.size_a = 0;
	ptr.size_b = 0;
	ptr.a = NULL;
	ptr.b = NULL;
	ptr.last_a = NULL;
	ptr.last_b = NULL;
	ptr.mv = NULL;
	return (ptr);
}

void	ft_push_swap(char **tab, int verbose)
{
	t_pusw	ptr;

	if (ft_check_error(tab) == CHECK_ERR)
		return (ft_putstr("Error\n"));
	
	ptr = ft_init_pusw(ptr, verbose);
	if (ft_fill_pusw(&ptr, tab) == CHECK_ERR)
		return (ft_putstr("Error\n"));

	ft_algo(&ptr);
	DEB("apres ft_algo\n");
	//ft_test_move(&ptr);
	ft_put_pusw(&ptr, NULL);
	DEB("apres affichage\n");

	ft_clear(&ptr, CHECK_OK);
	DEB("apres ft_clear\n");

	//ft_put_move(ptr.mv);
}

static int	ft_error(void)
{
	ft_putstr("Error\n");
	return (CHECK_ERR);
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
	if (ac == 2 + verbose)
	{
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