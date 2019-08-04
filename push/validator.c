/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:54:00 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/04 17:52:50 by jrheeder         ###   ########.fr       */
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

t_stack		*normalise(t_stack **stack)
{
	t_stack	*dog;
	t_stack	*s_tmp;
	t_stack	*ret;
	int		*order;
	int		count;
	int		i;

	s_tmp = *stack;
	order = (int *)malloc(sizeof(int) * list_length(stack));
	i = -1;
	while (s_tmp)
	{
		dog = *stack;
		count = 1;
		while (dog)
		{
			if (s_tmp->num > dog->num)
				count++;
			dog = dog->next;
		}
		order[++i] = count;
		s_tmp = s_tmp->next;
	}
	ret = malloc(sizeof(t_stack));
	ret->num = order[i--];
	ret->next = NULL;
	while (i >= 0)
		push(&ret, order[i--]);
	return (ret);
}
