/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:12:48 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 19:26:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_optimize(t_move *mv)
{
	int		prev;
	t_move	*tmp;

	while (tmp)
	{
		prev = tmp->num_mv;
		if (prev == SA && tmp->num_mv == SB)
			ft_change_to_ss(mv, tmp);
		else if (prev == RA && tmp->num_mv == RB)
			ft_change_to_rr(mv, tmp);
		else if (prev == RRA && tmp->num_mv == RRB)
			ft_change_to_rrr(mv, tmp);
		else if (prev == PA && tmp->num_mv == PB)
			ft_change_to_erase(mv, tmp);
		tmp = tmp->next;
	}
}