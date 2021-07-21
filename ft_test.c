/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:20:46 by user42            #+#    #+#             */
/*   Updated: 2021/07/21 12:44:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

void	ft_put_pusw(t_pusw *ptr)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		field;

	field = 10;
	ft_put_last_move(ptr->mv);
	//ft_put_move(ptr->mv);
	tmp_a = ptr->a;
	tmp_b = ptr->b;
	ft_printf("%*c\t%*c\n", field, 'A', field, 'B');
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf("%*i", field, tmp_a->nb);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("%*s", field, "");
		if (tmp_b)
		{
			ft_printf("\t%*i\n", field, tmp_b->nb);
			tmp_b = tmp_b->next;
		}
		else
			ft_printf("\t%*s\n", field, "");
	}
	ft_printf("\n");
}

void	ft_test_move(t_pusw *ptr)
{
	ft_put_pusw(ptr);
	ft_sa(ptr);

	ft_pb(ptr);
	ft_pb(ptr);

	ft_pa(ptr);

	ft_ra(ptr);

	ft_rra(ptr);

	ft_pb(ptr);
	ft_pb(ptr);

	ft_pb(ptr);
	ft_pb(ptr);
	ft_pb(ptr);
	ft_printf("---------------------\n");
	ft_put_pusw(ptr);
	ft_printf("---------------------\n");

	ft_sb(ptr);

	ft_pa(ptr);
	ft_pa(ptr);

	ft_pb(ptr);

	ft_rb(ptr);

	ft_rrb(ptr);

	ft_pa(ptr);
	ft_pa(ptr);

	ft_printf("---------------------\n");
	ft_put_pusw(ptr);
	ft_printf("---------------------\n");
	
	ft_rr(ptr);
	ft_rrr(ptr);
	ft_ss(ptr);
}