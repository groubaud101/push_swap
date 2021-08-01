/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:29:59 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 19:51:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

static void	ft_fill_the_moves(t_pusw *ptr)
{
	ptr->moves[SA] = "sa";
	ptr->moves[SB] = "sb";
	ptr->moves[SS] = "ss";
	ptr->moves[PA] = "pa";
	ptr->moves[PB] = "pb";
	ptr->moves[RA] = "ra";
	ptr->moves[RB] = "rb";
	ptr->moves[RR] = "rr";
	ptr->moves[RRA] = "rra";
	ptr->moves[RRB] = "rrb";
	ptr->moves[RRR] = "rrr";
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

void	ft_push_swap(char **tab, int verbose)
{
	t_pusw	ptr;

	if (ft_check_error(tab) == CHECK_ERR)
		return (ft_putstr("Error\n"));
	
	ptr = ft_init_pusw(ptr, verbose);
	ft_fill_the_moves(&ptr);
	if (ft_fill_pusw(&ptr, tab) == CHECK_ERR)
		return (ft_putstr("Error\n"));

	ft_algo(&ptr);
	DEB("apres ft_algo\n");
	if (ptr.verbose)
		ft_put_pusw(&ptr, -1);
	DEB("apres affichage pusw\n");
	ft_optimize(&ptr);

	ft_put_move(&ptr);
	DEB("apres affichage move\n");

	DEB("liste triée ? ");
	if (ft_check_order(ptr.a) == CHECK_OK)
		DEB("OUI\n");
	else
		DEB("NON !!!\n");
	ft_clear(&ptr, CHECK_OK);
	DEB("apres ft_clear\n");

}
