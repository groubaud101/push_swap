/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verbose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:15:34 by user42            #+#    #+#             */
/*   Updated: 2021/08/12 23:47:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"

static t_stack	*ft_put_one_stack_a(t_stack *tmp)
{
	if (tmp)
		ft_printf("%*i(%3i)", 15 - 5, tmp->nb, tmp->location);
	else
		return (NULL);
	return (tmp->next);
}

static t_stack	*ft_put_one_stack_b(t_stack *tmp)
{
	if (tmp)
	{
		ft_printf("\t%*i(%3i)\n", 15 - 5, tmp->nb, tmp->location);
		return (tmp->next);
	}
	ft_printf("\n");
	return (NULL);
}

void	ft_put_pusw(t_pusw *ptr, int num_mv)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (num_mv >= 0)
		ft_printf("Move : %s\n", ptr->moves[num_mv]);
	else
		ft_printf("No new move\n");
	tmp_a = ptr->a;
	tmp_b = ptr->b;
	ft_printf("%*c\t%*c\n", 15, 'A', 15, 'B');
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
			tmp_a = ft_put_one_stack_a(tmp_a);
		else
			ft_printf("%*s", 15, "");
		if (tmp_b)
			tmp_b = ft_put_one_stack_b(tmp_b);
		else
			ft_printf("\t%*s\n", 15, "");
	}
	ft_printf("\n");
}
