/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 15:31:00 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 23:48:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_ss(t_pusw *ptr)
{
	int	verbose;

	verbose = ptr->verbose;
	ptr->verbose = 0;
	ft_sa(ptr);
	ft_sb(ptr);
	ptr->verbose = verbose;
	ft_lstadd_move(&ptr->mv, "ss");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr);
	return (CHECK_ERR);
}

int		ft_rr(t_pusw *ptr)
{
	int	verbose;

	verbose = ptr->verbose;
	ptr->verbose = 0;
	ft_ra(ptr);
	ft_rb(ptr);
	ptr->verbose = verbose;
	ft_lstadd_move(&ptr->mv, "rr");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr);
	return (CHECK_OK);
}

int		ft_rrr(t_pusw *ptr)
{
	int	verbose;

	verbose = ptr->verbose;
	ptr->verbose = 0;
	ft_rra(ptr);
	ft_rrb(ptr);
	ptr->verbose = verbose;
	ft_lstadd_move(&ptr->mv, "rrr");
	if (ptr->verbose == 1)
		ft_put_pusw(ptr);
	return (CHECK_OK);
}
