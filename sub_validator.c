/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:49:10 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/25 15:48:09 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "stdio.h"

int		valid_input_string(int ac, char **av)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(av[1], ' ');
	i = 0;
	if (!only_digits(av[1]))
		return (0);
	if (!dupe_check(ac, av))
		return (0);
	while (arr[i])
	{
		if (ft_int_overflows(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int		valid_input_int(int ac, char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!only_digits(av[i]))
			return (0);
		if (ft_int_overflows(av[i]))
			return (0);
		i++;
	}
	if (!dupe_check(ac, av))
		return (0);
	return (1);
}