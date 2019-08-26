/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:54:00 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/15 22:13:54 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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

int		dupe_check(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[i + j] != '\0')
		{
			if (ft_strequ(av[i], av[i + j]))
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
		if (!valid_input_string(av))
			return (0);
	}
	else if (ac > 2)
	{
		if (!valid_input_int(av))
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

t_stack		*normalize(t_stack **stack)
{
	t_stack	*s_tmp;
	t_stack *tmp;
	t_stack	*ret;
	static int *order;
	int		count;
	int		i;

	s_tmp = *stack;
	order = (int*)malloc(sizeof(int) * list_length(stack));
	i = -1;
	ret = NULL;
	while (s_tmp)
	{
		tmp = *stack;
		count = 1;
		while (tmp != NULL)
		{
			if (s_tmp->num > tmp->num)
				count++;
			tmp = tmp->next;
		}
		order[++i] = count;
		s_tmp = s_tmp->next;
	}
	// ret = stack_new(order[i--]);
	while (i >= 0)
		push(&ret, order[i--]);
	free(order);
	return (ret);
}
