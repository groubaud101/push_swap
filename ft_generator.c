/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:43:57 by user42            #+#    #+#             */
/*   Updated: 2021/07/16 11:54:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rand_a_number(int min, int max)
{
	static int rand_is_seeded = 0;

	if(!rand_is_seeded)
	{
		srand(time(NULL));
		rand_is_seeded = 1;
	}
	return rand() % (max - min + 1) + min;
}

void    ft_generator(int size, int min, int max)
{
	int *tab;
	int i;
	int j;
	int r;

	if (max - min < size)
	{
		printf("too few possibilities in this size");
		return ;
	}
	tab = (int *)malloc(sizeof(*tab) * size);
	while (i < size)
		tab[i++] = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		r = rand_a_number(min, max);
		while (j < i)
		{
			if (tab[j] == r)
				break;
			j++;
		}
		if (tab[j] != r)
		{
			tab[j] = r;
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		printf("%i ", tab[i++]);
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		printf("./a.out <nb of numero> <min> <max>");
	else
		ft_generator(atoi(av[1]), atoi(av[2]), atoi(av[3]));
	return (0);    
}