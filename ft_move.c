/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:13:42 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:44:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	ft_lstadd_back_move(t_move **alst, t_move *new)
{
	t_move	*lst;

	if (*alst)
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

static t_move	*ft_lstnew_move(int	num_mv)
{
	t_move	*lst;

	lst = (t_move *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->num_mv = num_mv;
	lst->next = NULL;
	return (lst);
}

int	ft_lstadd_move(t_move **mv, int num_mv)
{
	t_move	*new;

	new = ft_lstnew_move(num_mv);
	if (!new)
		return (CHECK_ERR);
	ft_lstadd_back_move(mv, new);
	return (CHECK_OK);
}

void	ft_put_move(t_pusw *ptr)
{
	int		ct;
	t_move	*mv;

	mv = ptr->mv;
	ct = 0;
	while (mv)
	{
		ft_printf("%s\n", ptr->moves[mv->num_mv]);
		mv = mv->next;
		ct++;
	}
	if (ptr->verbose)
		ft_printf("nb de mv : %i\n", ct);
}
