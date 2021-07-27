/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 21:20:46 by user42            #+#    #+#             */
/*   Updated: 2021/07/27 19:50:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

void	do_nothing(char *str, ...)
{
	va_list params;

	va_start(params, str);
	va_end(params);
}

void	ft_test_move(t_pusw *ptr)
{
	ft_put_pusw(ptr, -1);
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
	ft_put_pusw(ptr, -1);
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
	ft_put_pusw(ptr, -1);
	ft_printf("---------------------\n");
	
	ft_rr(ptr);
	ft_rrr(ptr);
	ft_ss(ptr);
}