/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:17:47 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/10 03:16:11 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdel(t_list *lst)
{
	t_list	*prev;
	t_list	*next;

		prev = lst -> prev;
		next = lst -> next;
		prev -> next = next;
		next -> prev = prev;
		lst -> prev = NULL;
		lst -> next = NULL;
}

void	sasb(t_list *lst)
{
	t_list	*next;
	int		c;

	next = lst -> next;
	c = lst -> content;
	lst -> content = next -> content;
	next -> content = c;
}

void	ss(t_list *lst, t_list *lst2)
{
	sasb(lst);
	sasb(lst2);
}

void	pa(t_list **lst, t_list **lst2)
{
	t_list	*topush;
	t_list	*b;
	ft_printf("pa\n");
	topush = *lst;
	if (topush -> next != topush)
		*lst = topush -> next;
	else
		*lst = NULL;
	ft_lstdel(topush);
	ft_lstadd_back(lst2, topush);
	b = *lst2;
	topush -> next = b;
	b -> prev = topush;
}

void	ra(t_list **lst)
{
	t_list	*temp;
	int		index;

	ft_printf("ra\n");
	*lst = (*lst)->next;
	temp = *lst;
	index = 1;
	while (temp && (temp != *lst || index == 1))
	{
		temp->index = index++;
		temp = temp->next;
	}
}

void	rra(t_list **lst)
{
	t_list	*temp;
	int		index;

	*lst = (*lst)->prev;
	temp = *lst;
	index = 1;
	while (temp && (temp != *lst || index == 1))
	{
		temp->index = index++;
		temp = temp->next;
	}
}
void	rr(t_list **lst, t_list **lst2)
{
	ra(lst);
	ra(lst2);
}

void	rrr(t_list **lst, t_list **lst2)
{
	rra(lst);
	rra(lst2);
}

void	ft_lstsimple(t_list *lst, int min)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	temp = lst;
	lst -> content = lst -> content - min;
	while (temp -> next && temp -> next != lst)
	{
		temp = temp-> next;
		lst -> content = lst -> content - min;
	}
}

void	ft_lstdesimple(t_list *lst, int min)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	temp = lst;
	lst -> content = lst -> content + min;
	while (temp -> next && temp -> next != lst)
	{
		temp = temp-> next;
		lst -> content = lst -> content - min;
	}
}

void	radixsort(t_list **lst, t_list **lst2)
{
	t_list	*temp;
	int		i;
	int		mbits;
	int		min;
	int		j;
	int		eol;
	int		max;

	i = 0;
	temp = *lst;
	mbits = ft_bits(temp);
	min = ft_min(temp);
	max = ft_indexmax(temp);
	ft_lstsimple(temp, min);

	while (i < mbits)
	{
		j = 0;
		while (j++ < max)
		{
			temp = *lst;
			if (((temp -> content >> i) & 1) == 1)
			{
				ra(lst);
			}
			else
			{
				pa(lst, lst2);
			}
			temp = *lst;
		}
		eol = 0;
		while (!eol && temp)
		{
			temp = *lst2;
			if(temp -> index >= temp -> next -> index)
				eol = 1;
			pa(lst2,lst);
		}
		i++;
	}
	ft_lstdesimple(temp, min);
}
