/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrheeder <jrheeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:50:44 by jrheeder          #+#    #+#             */
/*   Updated: 2019/07/25 15:50:45 by jrheeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int		avg_of_nodes(t_stack *head)
{
	int		count;
	int		sum;
	int		avg;
	t_stack	*current;
	if (!head)
		return (-1);

	count = 0;
	sum = 0;
	avg = 0;
	current = head;
	while (current != NULL)
	{
		count++;
		sum += current->num;
		current = current->next;
	}
	avg = sum / count;
	return (avg);
}
