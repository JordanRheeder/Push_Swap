/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:01:03 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/04 17:09:00 by jrheeder         ###   ########.fr       */
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

	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("ps.c: Error\n", 2);
		return (0);
	}
	if (valid_input(argc, argv))
	{
		stack_a = stack_popu(argc, argv);
		do_sort_5(&stack_a, &stack_b);
	}
	return (0);
}
