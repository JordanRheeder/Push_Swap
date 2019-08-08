/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:45:03 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/04 15:01:37 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	do_sort_3(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	last;

	first = (*a)->num;
	second = (*a)->next->num;
	last = (*a)->next->next->num;
	
	if (first > second && first < last)
		print_do_op("sa", a, b);
	else if (first > second && second > last)
		{
			print_do_op("sa", a, b);
			print_do_op("rra", a, b);
		}
	else if (first > second && first > last)
		print_do_op("ra", a, b);
	else if (first < second && first < last)
	{
		print_do_op("sa", a, b);
		print_do_op("ra", a, b);
	}
	else
		print_do_op("rra", a, b);
}

void	normDoSort5Shorten1st(t_stack **a, t_stack **b)
{
	print_do_op("rra", a, b);
	print_do_op("sa", a, b);
	print_do_op("ra", a, b);
//	print_do_op("ra", a, b);
}

void	normDoSort5Shorten2nd(t_stack **a, t_stack **b)
{
	print_do_op("sa", a, b);
	print_do_op("ra", a, b);
	print_do_op("sa", a, b);
	print_do_op("rra", a, b);
}

int		find_last(t_stack *a)
{
	int ret;
	ret = 0;
	while (a)
	{
		if (a->next == NULL)
			ret = a->num;
		a = a->next;
	}
	return (ret);
}
#include <stdio.h>
void	do_sort_5(t_stack **a, t_stack **b)
{
	int first;
	int second;
	int last;
	
	print_do_op("pb", a, b);
	print_do_op("pb", a, b);
	if (!sorted((*a)))
		do_sort_3(&(*a), b);
	while (!sorted(*a) || (*b))
	{
		first = (*a)->num;
		second = (*a)->next->num;
		last = (find_last(*a));
		if (first > second && first < last && first < (*a)->next->next->num)
			print_do_op("sa", a, b);
		else if (first > last)
			print_do_op("ra", a, b);
		else if (list_length(a) == 4 && first > (*a)->next->next->num && first < last)
		{
			normDoSort5Shorten1st(a, b);
			printf("Doing Sub-sort 1.1");
		}
		else if (list_length(a) == 5 && first < (*a)->next->next->next->num && first < last)
		{
			normDoSort5Shorten2nd(a, b);
			printf("Doing sub-sort 2.0");
		}
		else if (list_length(a) == 5 && first > (*a)->next->next->next->num && first < last)
		{
			normDoSort5Shorten1st(a, b);
			printf("Doing sub-sort 1.2");
		}
		if (*b)
			print_do_op("pa", a, b);
	}
}
