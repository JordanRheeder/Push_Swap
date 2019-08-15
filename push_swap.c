/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:01:03 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 21:57:31 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_len;

	stack_len = 0;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("ps.c: Error\n", 2);
		return (0);
	}
	if (valid_input(argc, argv))
	{
		if (sorted(stack_a = stack_popu(argc, argv)))
			return (0);
		stack_b = NULL;
		stack_len = list_length(&stack_a);
		if (stack_len == 3)
			do_sort_3(&stack_a, &stack_b);
		else if (stack_len >= 4 && stack_len <= 5)
			do_sort_5(&stack_a, &stack_b);
		else if (stack_len >= 20 && stack_len <= 100)
			do_sort_20(&stack_a, &stack_b);
	}
	return (0);
}
