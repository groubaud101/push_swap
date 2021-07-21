/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:15:34 by user42            #+#    #+#             */
/*   Updated: 2021/07/21 19:21:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

static void	ft_put_last_move(t_move *mv)
{
	if (!mv)
	{
		printf("No move yet\n");
		return ;
	}
	else
		printf("Move :\n");
	while (mv->next)
		mv = mv->next;
	ft_printf("%s\n", mv->move);
}

void	ft_put_pusw(t_pusw *ptr)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_put_last_move(ptr->mv);
	tmp_a = ptr->a;
	tmp_b = ptr->b;
	ft_printf("%*c\t%*c\n", 15, 'A', 15, 'B');
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf("%*i(%2i)", 15 - 4, tmp_a->nb, tmp_a->location);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("%*s", 15, "");
		if (tmp_b)
		{
			ft_printf("\t%*i(%2i)\n", 15 - 4, tmp_b->nb, tmp_b->location);
			tmp_b = tmp_b->next;
		}
		else
			ft_printf("\t%*s\n", 15, "");
	}
	ft_printf("\n");
}
