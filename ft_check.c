/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 11:45:18 by user42            #+#    #+#             */
/*   Updated: 2021/07/21 12:40:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "libft.h"


#include "ft_printf.h"

int	ft_check_error(char **tab)
{
	int	i;
	int sign;
	int	max;

	if (tab == NULL)
		return (CHECK_ERR);
	while (*tab)
	{
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
