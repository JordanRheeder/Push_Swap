/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:49:10 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/29 15:28:05 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

int		valid_input_string(char **av)
{
	static char	**arr;
	int			i;

	arr = ft_strsplit(av[1], ' ');
	i = 0;
	if (!only_digits(av[1]))
		return (0);
	if (!dupe_check(arr))
		return (0);
	while (arr[i])
	{
		if (ft_int_overflows(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int		valid_input_int(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_int_overflows(av[i]))
			return (0);
		if (!only_digits(av[i]))
			return (0);
		i++;
	}
	if (!dupe_check(av))
		return (0);
	return (1);
}

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
