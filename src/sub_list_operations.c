/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_list_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:48:58 by jrheeder          #+#    #+#             */
/*   Updated: 2019/08/26 12:55:35 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void		print_stack(t_stack **stack)
{
	t_stack *print;

	print = *stack;
	while (print != NULL)
	{
		ft_putnbr(print->num);
		ft_putchar('\n');
		print = print->next;
	}
}

int			list_length(t_stack **head)
{
	t_stack *tmp;
	int		cnt;

	cnt = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

int			pop(t_stack **head)
{
	t_stack	*next_node;
	int		ret;

	if (*head == NULL)
		return (-1);
	next_node = NULL;
	ret = -1;
	next_node = (*head)->next;
	ret = (*head)->num;
	free(*head);
	*head = next_node;
	return (ret);
}
