/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:49:10 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 22:13:38 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int		valid_input_string(char **av)
{
	static char	**arr;
	int		i;

	arr = ft_strsplit(av[1], ' ');
	i = 0;
	if (!only_digits(av[1]))
	{
		free(arr); // empty malloc
		return (0); //kill
	}
	if (!dupe_check(arr))
	{
		free(arr); // empty malloc
		return (0); //kill
	}
	while (arr[i])
	{
		if (ft_int_overflows(arr[i]))
		{
			free(arr); // empty malloc
			return (0); //kill
		}
		i++;
	}

	return (1); //kill
}

int		valid_input_int(char **av)
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
	if (!dupe_check(av))
		return (0);
	return (1);
}
