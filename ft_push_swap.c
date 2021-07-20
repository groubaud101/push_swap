/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 23:16:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

void	ft_push_swap(char **tab, int verbose)
{
	t_pusw	ptr;

	if (ft_check_error(tab) == CHECK_ERR)
		return (ft_putstr("Error\n")) ;
	ptr = (t_pusw){verbose, 0, 0, NULL, NULL, NULL};
	if (ft_init_pusw(&ptr, tab) == CHECK_ERR)
		return (ft_putstr("Error\n"));


	ft_test_move(&ptr);
	//ft_put_move(ptr.mv);
}

static int	ft_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

int main(int ac, char **av)
{
	char	**tab;
	int		verbose;

	verbose = ft_check_verbose(ac, av);
	if (verbose == -1 || ac == 1 + (verbose > 0))
		return (ft_error());
	if (ac == 2 + (verbose > 0))
	{
		if (verbose == 1)
			tab = ft_split(av[2], ' ');
		else
			tab = ft_split(av[1], ' ');
		ft_push_swap(tab, (verbose > 0));
		ft_free_tab(tab);
	}
	else
		ft_push_swap(av + 1, (verbose > 0));
	return (0);	
}