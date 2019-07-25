/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:01:03 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/25 15:53:14 by jrheeder         ###   ########.fr       */
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
	int		count;
	char	ops[4][4] = {"rra", "ra", "pb"};

	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = stack_new(argc, argv);
	count = list_length(&stack_a);
	printf("list size = %d\n", count);
	ft_putendl_fd(ops[1], 1);
	return (0);
}
