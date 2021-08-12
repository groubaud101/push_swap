/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_below_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:19:55 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 23:10:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_three(t_pusw *ptr, int second, int third)
{
	if (second > third)
	{
		ft_sa_check_sb(ptr);
		ft_rra_check_rrb(ptr);
	}
	else
		ft_ra_check_rb(ptr);
}

void		ft_algo_three(t_pusw *ptr)
{
	int	first;
	int	second;
	int third;

	if (ft_check_order(ptr->a) == CHECK_OK)
		return ;
	first = ptr->a->location;
	second = ptr->a->next->location;
	third = ptr->a->next->next->location;
	if (first > second && first < third)
		ft_sa_check_sb(ptr);
	else if (first > second && first > third)
		ft_three(ptr, second, third);
	else if (first > second)
		ft_sa_check_sb(ptr);
	else if (first < second && first > third)
		ft_rra_check_rrb(ptr);
	else
	{
		ft_rra_check_rrb(ptr);
		ft_sa_check_sb(ptr);
	}
}

static void	ft_algo_four_five(t_pusw *ptr)
{
	int	size;
	int	i;

	size = ptr->total_size;
	while (--size >= 3
		&& ft_can_insert(ptr, ptr->a,
		ptr->a->location, ptr->last_a->location) == CHECK_ERR)
		ft_pb(ptr);
	if (size == 2)
		ft_algo_three(ptr);
	while (ptr->b && size < ptr->total_size)
	{
		i = 0;
		while (ptr->b && i++ < 10
			&& ft_can_insert(ptr, ptr->a,
			ptr->b->location, ptr->last_a->location) == CHECK_ERR)
			ft_ra_or_rra_pa(ptr, ptr->a);
		ft_pa(ptr);
		size++;
	}
	i = 0;
	while (ptr->a->location > 0 && i++ < 10)
		ft_ra_or_rra(ptr, ptr->a);
}

void	ft_algo_below_five(t_pusw *ptr)
{
	int	size;

	size = ptr->size_a;
	if (size == 1)
		return ;
	if (size == 2)
	{
		if (ptr->a->location > ptr->a->next->location)
			ft_sa_check_sb(ptr);		
	}
	else if (size == 3)
		ft_algo_three(ptr);
	else
		ft_algo_four_five(ptr);
}
