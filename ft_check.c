/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/20 23:00:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"

static char **ft_skip_v(char **tab)
{
	if (ft_strcmp("-v", *tab) == 0)
		tab++;
	return (tab);
}

int	ft_check_error(char **tab)
{
	int	i;
	int sign;
	int	max;

	if (tab == NULL)
		return (CHECK_ERR);
	while (*tab)
	{
		if (ft_skip_v(tab) == NULL)
			return(CHECK_OK);
		i = 0;
		sign = ((*tab)[i] == '-' || (*tab)[i] == '+');
		i += sign;
		max = 10 + sign;
		while ((*tab)[i])
		{
			if (ft_isdigit((*tab)[i]) == 0 || (i >= max))
				return (CHECK_ERR);
			i++;
		}
		tab++;
	}
	return (CHECK_OK);
}

int	ft_check_verbose(int ac, char **av)
{
	int	verb;
	int	save;

	verb = 0;
	if (ac == 2)
		return (0);
	ac--;
	save = 0;
	while (ac > 0)
	{
		if (ft_strcmp("-v", av[ac]) == 0)
		{
			verb++;
			save = ac;
		}
		ac--;
	}
	if (verb > 1)
		return (-1);
	return (save);
}
