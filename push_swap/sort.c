/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 17:17:47 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/05 01:44:59 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdel(t_list *lst)
{
	t_list	*prev;
	t_list	*next;

	lst = ft_lstlast(lst);
	if (lst -> index != 1)
	{
		prev = lst -> prev;
		next = lst -> next;
		prev -> next = next;
		next -> prev = prev;
		lst -> prev = NULL;
		lst -> next = NULL;
	}
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

void	pa(t_list *lst, t_list **lst2)
{
	t_list	*topush;

	topush = ft_lstlast(lst);
	ft_lstdel(lst);
	ft_lstadd_back(lst2, topush);
}

void	ra(t_list **lst)
{
	t_list	*temp;
	int		index;

	*lst = (*lst)->next;
	temp = *lst;
	index = 1;
	while (temp && (temp != *lst || index == 1))
	{
		temp->index = index++;
		ft_printf("%d\n", temp->index);
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
		ft_printf("%d\n", temp->index);
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