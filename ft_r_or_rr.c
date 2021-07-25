/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_or_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:37:22 by user42            #+#    #+#             */
/*   Updated: 2021/07/25 15:16:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ra_or_rra_chunk(t_pusw *ptr, t_stack *tmp, int div, int chunk)
{
	int		team_r;
	int		i;
	int		team_rr;

	i = 1;
	DEB("START ra or rra_chunk\n");
	while (tmp)
	{
		if (tmp->location / div == chunk)
			break;
		tmp = tmp->next;
		i++;
	}
	team_r = i;
	DEB("team_r : %i\n", team_r);
	team_rr = i;
	while (tmp)
	{
		if (tmp->location / div == chunk)
			team_rr = i;
		i++;
		tmp = tmp->next;
	}
	DEB("team_rr : %i, size_a : %i\n", team_rr, ptr->size_a);
	if (team_r < ptr->size_a - team_rr)
		ft_ra_check_rb(ptr);
	else
		ft_rra_check_rrb(ptr);
	DEB("END ra or rra_chunk\n");
}

void	ft_ra_or_rra_pa(t_pusw *ptr, t_stack *tmp_a)
{
	int		team_r;
	int		i;
	int		team_rr;

	i = 0;
	DEB("START ra or rra_pa\n");
	while (tmp_a)
	{
		if (tmp_a->location > ptr->b->location)
			break;
		tmp_a = tmp_a->next;
		i++;
	}
	team_r = i;
	DEB("team_r : %i\n", team_r);
	team_rr = i;
	while (tmp_a)
	{
		if (tmp_a->location > ptr->b->location)
			team_rr = i;
		i++;
		tmp_a = tmp_a->next;
	}
	DEB("team_rr : %i, size_a : %i\n", team_rr, ptr->size_a);
	if (team_r <= ptr->size_a - team_rr)
	{
		DEB("team_r win, first at the end\n");
		ft_simple_ra(ptr);
	}
	else
	{
		DEB("team_rr win, last at the begin\n");
		ft_simple_rra(ptr);
	}
	DEB("END ra or rra\n");
}