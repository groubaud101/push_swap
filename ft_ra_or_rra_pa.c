/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_or_rra_pa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:36:13 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:54:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_team_r(t_pusw *ptr, t_stack *tmp_a)
{
	int		tmp_prev;
	int		i;

	i = 0;
	tmp_prev = ptr->last_a->location;
	while (tmp_a)
	{
		if (ft_can_insert(ptr, tmp_a, ptr->b->location, tmp_prev) == CHECK_OK)
			break ;
		tmp_prev = tmp_a->location;
		tmp_a = tmp_a->next;
		i++;
	}
	return (i);
}

static int	ft_team_rr(t_pusw *ptr, t_stack *tmp_a)
{
	int		tmp_prev;
	int		i;
	int		team_rr;

	i = 0;
	team_rr = 0;
	tmp_prev = ptr->last_a->location;
	while (tmp_a)
	{
		if (ft_can_insert(ptr, tmp_a, ptr->b->location, tmp_prev) == CHECK_OK)
			team_rr = i;
		tmp_prev = tmp_a->location;
		tmp_a = tmp_a->next;
		i++;
	}
	return (team_rr);
}

int	ft_ra_or_rra_pa(t_pusw *ptr, t_stack *tmp_a)
{
	int		team_r;
	int		team_rr;
	int		i;

	i = 0;
	team_r = ft_team_r(ptr, tmp_a);
	if (team_r == ptr->total_size)
		return (CHECK_ERR);
	team_rr = ptr->size_a - ft_team_rr(ptr, tmp_a);
	if (team_r < team_rr)
		while (i++ < team_r)
			ft_simple_ra(ptr);
	else
		while (i++ < team_rr)
			ft_simple_rra(ptr);
	return (CHECK_OK);
}
