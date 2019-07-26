/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:45:03 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/26 15:22:12 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	do_sort_3(t_stack **a, t_stack **b)
{
	t_stack	*tempa;
	t_stack	*tempb;

	tempa = *a;
	tempb = *b;
	if (tempa->num > tempa->next->num && tempa->num < tempa->next->next->num)
		ft_putendl_fd("sa", 1);
	else if (tempa->num > tempa->next->num && tempa->next->num > tempa->next->next->num)
		{
			ft_putendl_fd("sa", 1);
			ft_putendl_fd("rra", 1);
		}
	else if (tempa->num > tempa->next->num && tempa->num > tempa->next->next->num)
		ft_putendl_fd("ra", 1);
	else if (tempa->num < tempa->next->num && tempa->num < tempa->next->next->num)
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("ra", 1);
	}
	else
	{
		ft_putendl_fd("rra", 1);
	}
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
	do_sort_3(&tempa, &tempb);
	if ((sorted(tempa)))
	{
		ft_putendl_fd("pa", 1);
		pa(&tempa, &tempb);
	}
	if ((tempa->num > tempa->next->num && tempa->num > tempa->next->next->num))
	{
		ft_putendl_fd("ra", 1);
		ra(&tempa);
	}
	ft_putendl_fd("pa", 1);
	pa(&tempa, &tempb);
}

// void	quickboi(int len, t_stack **a, t_stack **b)
// {

// }