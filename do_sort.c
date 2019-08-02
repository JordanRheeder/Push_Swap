/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:45:03 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/02 20:53:57 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int		three(t_stack *stack, int a, int b, int c)
{
	
}

void	do_sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	
	if (a > b && a < c)
		ft_putendl_fd("sa", 1);
	else if (a > b && b > c)
		{
			ft_putendl_fd("sa", 1);
			ft_putendl_fd("rra", 1);
		}
	else if (a > b && a > c)
		ft_putendl_fd("ra", 1);
	else if (a < b && a < c)
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("ra", 1);
	}
	else
		ft_putendl_fd("rra", 1);
}
#include <stdio.h>
void	do_sort_5(t_stack **a, t_stack **b) // check if it has 5 arguments or count through the array and check if av[5] exists.
{
	t_stack	*tempa;
	t_stack	*tempb;

	tempa = *a;
	tempb = *b;
	
	ft_putendl_fd("pb", 1);
	pb(&tempb, &tempa);
	ft_putendl_fd("pb", 1);
	pb(&tempb, &tempa);
	do_sort_3(&tempa);
	if ((sorted(tempa)))
	{
		ft_putendl_fd("pa", 1);
		pa(&tempa, &tempb);
		if ((tempa->num > tempa->next->num && tempa->num > tempa->next->next->num))
		{
			ft_putendl_fd("ra", 1);
			ra(&tempa);
		}
	}
	// if ((tempa->num > tempa->next->num && tempa->num > tempa->next->next->num))
	// {
	// 	ft_putendl_fd("ra", 1);
	// 	ra(&tempa);
	// }
	ft_putendl_fd("pa", 1);
	pa(&tempa, &tempb);
}

// void	quickboi(int len, t_stack **a, t_stack **b)
// {

// }