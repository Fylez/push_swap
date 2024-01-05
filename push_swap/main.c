/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:34 by lzaengel          #+#    #+#             */
/*   Updated: 2024/01/05 01:42:14 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_exit(t_list *lst, char *reason)
{
	t_list	*next;

	if (lst == NULL)
	{
		exit(0);
	}

	ft_printf ("%s\n", reason);
	if (lst->prev)
	{
		lst->prev->next = NULL;
	}
	while (lst != NULL)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	exit(0);
}

int	ft_isdigit(int character)
{
	if (character < '0' || character > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi( const char *theString, t_list *lst)
{
	long int		i;
	long int		result;
	int				neg;

	i = 0;
	neg = 1;
	result = 0;
	if (theString[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	else if (theString[i] == '+')
		i++;
	while (theString[i])
	{
		if (ft_isdigit(theString[i]))
		{
			result = result * 10 + theString[i] - '0';
			i++;
		}
		else
			ft_exit(lst, "Invalid characters");
	}
	return (result * neg);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp -> next && temp -> next != lst)
	{	
		temp = temp -> next;
	}
	return (temp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prv;
	int		indexlast;
	int		index;

	if (!*lst)
	{
		new -> index = 1;
		new->prev = NULL;
		*lst = new;
	}
	else
	{
		prv = ft_lstlast(*lst);
		prv -> next = new;
		new -> prev = prv;
		indexlast = prv -> index;
		index = indexlast + 1;
		new -> index = index;
	}
}

void	ft_lstprint(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return ;
	temp = lst;
	ft_printf("%d\n", temp->content);
	ft_printf("%d\n", temp->index);
	while (temp -> next && temp -> next != lst)
	{
		temp = temp-> next;
		ft_printf("%d\n", temp->content);
		ft_printf("%d\n", temp->index);
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;


	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	main(int argc, char **argv)
{
	int			j;
	t_list		*lst;
	t_list		*lst2;
	t_list		*last;
	int			nbr;

	j = 1;
	lst = 0;
	lst2 = 0;
	nbr = 0;
	if (argc == 1)
		ft_exit (lst, "No argument");
	while (argv[j])
	{
		nbr = ft_atoi(argv[j], lst);
		ft_lstadd_back(&lst, ft_lstnew(nbr));
		j++;
	}
	checkdup(lst);
	last = ft_lstlast(lst);	
	lst -> prev = last;
	last -> next = lst;
	ft_lstprint(lst);
	rra(&lst);
	ft_lstprint(lst);
	//sasb(lst);
	//pa(lst, &lst2);
	//ft_lstprint(lst2);
	ft_exit(lst, "End of program");
}
