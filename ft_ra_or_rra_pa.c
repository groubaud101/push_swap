/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_or_rra_pa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:36:13 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 19:59:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_the_greatest(t_stack *tmp, int the_greatest)
{
	while (tmp)
	{
		if (tmp->location > the_greatest)
			return (CHECK_ERR);
		tmp = tmp->next;
	}
	return (CHECK_OK);
}

int	ft_can_insert(t_pusw *ptr, t_stack *tmp_a, int location, int tmp_prev)
{
	if ((location < tmp_a->location 
		&& location > tmp_prev)
		|| ((ft_the_greatest(tmp_a, location) == CHECK_OK
		|| location < ptr->a->location)
		&& ft_check_order(tmp_a) == CHECK_OK))
		return (CHECK_OK);
	return (CHECK_ERR);
}

static int	ft_team_r(t_pusw *ptr, t_stack *tmp_a)
{
	int		tmp_prev;
	int		i;

	i = 0;
	tmp_prev = ptr->last_a->location;
	while (tmp_a)
	{
		if (ft_can_insert(ptr, tmp_a, ptr->b->location, tmp_prev) == CHECK_OK)
			break;
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

void	ft_ra_or_rra_pa(t_pusw *ptr, t_stack *tmp_a)
{
	int		team_r;
	int		team_rr;

	team_r = ft_team_r(ptr, tmp_a);
	team_rr = ft_team_rr(ptr, tmp_a);
	if (team_r <= ptr->size_a - team_rr)
		ft_simple_ra(ptr);
	else
		ft_simple_rra(ptr);
}