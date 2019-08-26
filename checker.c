/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:28:12 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/04 16:59:19 by jrheeder         ###   ########.fr       */
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
		ERROR;
	if (valid_input(ac, av))
	{
		stack_a = stack_popu(ac, av);
		if (!(read_input(&stack_a, &stack_b, &line)))
			ERROR;
	}
	else
		ERROR;
	if (sorted(stack_a) && (!stack_b))
	{
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
		ERROR;
	return (0);
}
