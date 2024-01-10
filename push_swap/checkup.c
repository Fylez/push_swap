/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:26 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/10 02:07:19 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkdup(t_list *lst)
{
	t_list	*tocheck;
	t_list	*next;

	tocheck = lst;
	while (tocheck)
	{
		next = tocheck -> next;
		while (next)
		{
			if (tocheck -> content == next->content)
				ft_exit(lst, "Duplicate numbers");
			next = next->next;
		}
		tocheck = tocheck -> next;
	}
}

int	ft_min(t_list *lst)
{
	t_list	*temp;
	int		min;

	if (!lst)
		return (0);
	temp = lst;
	min = lst->content;
	while (temp -> next && temp -> next != lst)
	{
		if (temp -> content < min)
			min = temp -> content;
		temp = temp -> next;
	}
	if (min >= 0)
		min = 0;
	return (min);
}

int	ft_indexmax(t_list *lst)
{
	t_list	*temp;
	int		max;
	int		i;

	if (!lst)
		return (0);
	temp = lst;
	max = lst->index;
	while (temp -> next && temp -> next != lst)
	{
		if (temp -> index > max)
			max = temp -> index;
		temp = temp -> next;
	}
	return (max);
}

int	ft_bits(t_list *lst)
{
	t_list	*temp;
	int		max;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	temp = lst;
	max = lst->content;
	while (temp -> next && temp -> next != lst)
	{
		if (temp -> content > max)
			max = temp -> content;
		temp = temp -> next;
	}
	if (temp -> content > max)
			max = temp -> content;
	while ((max >> i) != 0)
		i++;
	return (i);
}
