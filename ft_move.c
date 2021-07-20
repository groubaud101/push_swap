/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:13:42 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 23:14:24 by user42           ###   ########.fr       */
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

static t_move	*ft_lstnew_move(const char *str)
{
	t_move	*lst;

	lst = (t_move *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->move = str;
	lst->next = NULL;
	return (lst);
}

int	ft_lstadd_move(t_move **mv, const char *str)
{
	t_move	*new;

	new = ft_lstnew_move(str);
	if (!new)
		return (CHECK_ERR);
	ft_lstadd_back_move(mv, new);
	return (CHECK_OK);
}

void	ft_put_last_move(t_move *mv)
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

void	ft_put_move(t_move *mv)
{
	if (!mv)
		return ;
	while (mv)
	{
		ft_printf("%s\n", mv->move);
		mv = mv->next;
	}
}