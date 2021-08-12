/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_or_rra_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:52:34 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 23:24:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_team_r(t_stack *tmp, int top)
{
	int		i;

	i = 0;
	while (tmp)
	{
		if (tmp->location <= top)
			break;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	ft_team_rr(t_stack *tmp, int top)
{
	int		i;
	int		team_rr;

	i = 0;
	team_rr = 0;
	while (tmp)
	{
		if (tmp->location <= top)
			team_rr = i;
		tmp = tmp->next;
		i++;
	}
	return (team_rr);
}

int	ft_ra_or_rra_chunk(t_pusw *ptr, t_stack *tmp, int top)
{
	int		team_r;
	int		i;
	int		team_rr;

	i = 0;
	team_r = ft_team_r(tmp, top);
	if (team_r == ptr->size_a)
		return (CHECK_ERR);

	team_rr = ptr->size_a - ft_team_rr(tmp, top);
	i = 0;
	if (team_r < team_rr)
		while (i++ < team_r)
			ft_ra_check_rb(ptr);
	else
		while (i++ < team_rr)
			ft_rra_check_rrb(ptr);
	return (CHECK_OK);
}
