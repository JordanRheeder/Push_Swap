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

#include "../push_swap.h"
#include "../libft/libft.h"

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

void	do_sort_5(t_stack **a, t_stack **b)
{
	int	min;
	int	max;

	min = find_min_or_max(*a, 0);
	max = find_min_or_max(*a, 1);
	push_min_or_max_b(a, b, 2, list_length(a));
	if (!(sorted(*a)))
		do_sort_3(a, b);
	while (*b)
	{
		if ((*b)->num == min)
			print_do_op("pa", a, b);
		else if ((*b)->num == max)
		{
			print_do_op("pa", a, b);
			print_do_op("ra", a, b);
		}
	}
}

void	do_sort_20(t_stack **a, t_stack **b)
{
	int	range;
	int i;

	range = 0;
	i = 1;
	while (*a)
	{
		range += 15;
		while (i < range)
		{
			if (!(*a))
				break ;
			if ((*a)->num <= range)
			{
				print_do_op("pb", a, b);
				i++;
			}
			else
				print_do_op("ra", a, b);
		}
	}
	i--;
	push_max_a(b, a, i);
}

void	do_sort_500(t_stack **a, t_stack **b)
{
	int	range;
	int	i;

	range = 0;
	i = 1;
	while (*a)
	{
		range += 37;
		while (i < range)
		{
			if (!(*a))
				break ;
			if ((*a)->num <= range)
			{
				print_do_op("pb", a, b);
				i++;
			}
			else
				print_do_op("ra", a, b);
		}
	}
	i--;
	push_max_a(b, a, i);
}
