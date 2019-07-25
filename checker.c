/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:28:12 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/25 16:12:03 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*line;

	stack_a = NULL;
	line = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		ft_putstr_fd("0:Error\n", 2);
		return (0);
	}
	if (valid_input(ac, av))
	{
		stack_a = stack_new(ac, av);
		if ((read_input(&stack_a, &stack_b, &line)))
		{
			ft_putstr_fd("1:Error\n", 2);
			return (0);
		}
	}
	else
	{
		ft_putstr_fd("2:Error\n", 2);
		return (0);
	}
	if (sorted(stack_a) && (!stack_b))
	{
		free(stack_a);
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
		ft_putstr_fd("KO\n", 1);
	printf("\n STACK A:\n");
	print_stack(&stack_a);
	printf("\n STACK B:\n");
	print_stack(&stack_b);
	printf("avg is: %d\n", avgOfNodes(stack_a));
	return (0);
}
