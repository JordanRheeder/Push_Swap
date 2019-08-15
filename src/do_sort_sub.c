/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:34:34 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 22:10:48 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_position(t_stack *stack, int value)
{
	int position;
	
	position = 1;
	while (stack)
	{
		if (stack->num == value)
		{
			return (position);
		}
		stack = stack->next;
		position++;
	}
	return (0);
}

int		find_min_or_max(t_stack *stack, int type)
{
	int min_or_max;

	min_or_max = stack->num;
	if (type == 0) // min
	{
		while (stack)
		{
			if (min_or_max > stack->num)
				min_or_max = stack->num;
			stack = stack->next;
		}
	}
	else if (type == 1) // max
	{
		while (stack)
		{
			if (min_or_max < stack->num)
				min_or_max = stack->num;
			stack = stack->next;
		}
	}
	return (min_or_max);
}

void	push_min_or_max_b(t_stack **a, t_stack **b, int repeat, int a_length)
{
	int iterator;
	int min;
	int max;

	iterator = 0;
	min = find_min_or_max(*a, 0);
	max = find_min_or_max(*a, 1);
	while (iterator < repeat)
	{
		if (find_position(*a, min) == 1 || find_position(*a, max) == 1)
		{
			print_do_op("pb", a, b);
			iterator++;
		}
		else if (find_position(*a, min) > a_length / 2 || find_position(*a, max) > a_length / 2)
			print_do_op("rra", a, b);
		else if (find_position(*a, min) < a_length / 2 || find_position(*a, max) < a_length / 2)
			print_do_op("ra", a, b);
	}
}

void	push_max_a(t_stack **b, t_stack **a, int repeat, int b_len)
{
	int i;
	int max;

	i = 0;
	max = find_min_or_max(*b, 1);
	while (i < repeat)
	{
		if (find_position(*b, max) == 1)
		{
			print_do_op("pa", a, b);
			i++;
			if (*b)
				max = find_min_or_max(*b, 1);
		}
		else if (find_position(*b, max) > b_len / 2)
			print_do_op("rrb", a, b);
		else if (find_position(*b, max) <= b_len / 2)
			print_do_op("rb", a, b);
	}
}
