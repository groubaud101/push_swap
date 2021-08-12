/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:29:59 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 22:54:28 by user42           ###   ########.fr       */
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
	if (ptr.verbose)
		ft_put_pusw(&ptr, -1);
	ft_optimize(&ptr);
	ft_put_move(&ptr);
	if (ptr.verbose)
		ft_put_pusw(&ptr, -1);	
	ft_clear(&ptr, CHECK_OK);
}
