/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:54:00 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/26 15:09:31 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "stdio.h"

int		only_digits(char *str)
{
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!(ft_isdigit(*str)) && (!(ft_iswhitespace(*str))))
			return (0);
		str++;
	}
	return (1);
}

int		dupe_check(int ac, char **av)
{
	char	**str;
	int		i;
	int		j;

	i = 1;
	str = NULL;
	if (ac == 2)
	{
		str = ft_strsplit(av[1], ' ');
		i = 0;
	}
	else
		str = av;
	while (str[i])
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (ft_strequ(str[i], str[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		valid_input(int ac, char **av)
{
	if (ac == 2)
	{
		if (!valid_input_string(ac, av))
			return (0);
	}
	else if (ac > 2)
	{
		if (!valid_input_int(ac, av))
			return (0);
	}
	return (1);
}

int		sorted(t_stack *stack_a)
{
	int temp;

	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		temp = stack_a->num;
		stack_a = stack_a->next;
		if (temp > stack_a->num && stack_a)
			return (0);
	}
	return (1);
}
