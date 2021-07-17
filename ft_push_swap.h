/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 12:26:40 by user42            #+#    #+#             */
/*   Updated: 2021/07/17 18:31:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stddef.h>

# define CHECK_OK 1
# define CHECK_ERR 0

# define SA ptr->tab[0]
# define SB ptr->tab[1]
# define SS ptr->tab[2]
# define PA ptr->tab[3]
# define PB ptr->tab[4]
# define RA ptr->tab[5]
# define RB ptr->tab[6]
# define RR ptr->tab[7]
# define RRA ptr->tab[8]
# define RRB ptr->tab[9]
# define RRR ptr->tab[10]

# define A ptr->a
# define B ptr->b
# define MV ptr->mv

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}t_stack;

typedef struct s_move
{
	char			move[4];
	struct s_move	*next;
}t_move;

typedef struct s_pusw
{
	size_t		size_a;
	size_t		size_b;
	t_stack		*a;
	t_stack		*b;
	t_move		*mv;
	int			(*tab[11])(struct s_pusw *ptr);
}t_pusw;

void	ft_free_tab(char **tab);
int		ft_clear_stack(t_stack **lst);

int		ft_init_pusw(t_pusw *ptr, char **tab);
int		ft_tab_move(t_pusw *ptr);

int		ft_sa(t_pusw *ptr);
int		ft_sb(t_pusw *ptr);
int		ft_ss(t_pusw *ptr);
int		ft_pa(t_pusw *ptr);
int		ft_pb(t_pusw *ptr);
int		ft_ra(t_pusw *ptr);
int		ft_rb(t_pusw *ptr);
int		ft_rr(t_pusw *ptr);
int		ft_rra(t_pusw *ptr);
int		ft_rrb(t_pusw *ptr);
int		ft_rrr(t_pusw *ptr);


#define TEST 1
#if TEST
# include <stdio.h>
void	ft_putlst(t_stack *lst);
void	ft_put_pusw(t_pusw *ptr);
#endif

#endif