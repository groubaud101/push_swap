/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:12:48 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 20:03:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

static int	ft_is_pa_and_pb(int num_mv1, int num_mv2)
{
	if ((num_mv1 == PA && num_mv2 == PB)
		|| (num_mv1 == PB && num_mv2 == PA))
		return (CHECK_OK);
	return (CHECK_ERR);
}

static int	ft_is_ra_and_rra(int num_mv1, int num_mv2)
{
	if ((num_mv1 == RA && num_mv2 == RRA)
		|| (num_mv1 == RRA && num_mv2 == RA))
		return (CHECK_OK);
	return (CHECK_ERR);
}

void	ft_optimize(t_pusw *ptr)
{
	t_move	*crt;
	t_move	*tmp;
	t_move	*prev;
	int		i;

	if (!ptr->mv)
		return ;
	crt = ptr->mv;
	prev = ptr->mv;
	tmp = NULL;
	i = 0;
	DEB("START ft_optimize\n");
	while (crt && crt->next)
	{
		DEB("\ndebut boucle crt : %i, ptr->mv : %i, i : %i \n",
				crt->num_mv, ptr->mv->num_mv, i);
		ft_put_move(ptr);
		if (ft_is_pa_and_pb(crt->num_mv, crt->next->num_mv) == CHECK_OK
			|| ft_is_ra_and_rra(crt->num_mv, crt->next->num_mv) == CHECK_OK)
		{
			DEB("delete two\n");
			tmp = crt->next->next;
			free(crt->next);
			free(crt);
			if (i == 0)
				ptr->mv = tmp;
			else
				prev->next = tmp;
			crt = ptr->mv;
			i = 0;
		}
		else
		{
			DEB("go next\n");
			prev = crt;
			crt = crt->next;
			i++;
		}
	}
	DEB("END ft_optimize\n");
}