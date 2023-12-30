/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:34 by lzaengel          #+#    #+#             */
/*   Updated: 2023/12/30 18:16:45 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdel(t_list *lst)
{
	t_list *prev;
	t_list *next;

	lst = ft_lstlast(lst);
	prev = lst -> prev;
	next = lst -> next;
	prev -> next = next;
	next -> prev = prev;
	lst -> prev = NULL;
	lst -> next = NULL;
}

void	ft_exit(t_list *lst, char *reason)
{
	t_list	*next;

	ft_printf ("%s\n", reason);
	if (lst == NULL)
		exit(0);
	next = lst -> next;
	free(lst);
	while (next != NULL && lst -> index <= next -> index)
	{
		lst = next;
		next = lst -> next;
		free(lst);
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
	t_list	*next;

	if (lst == NULL)
		return (NULL);
	next = lst -> next;
	while (next != NULL && lst -> index <= next -> index)
	{	
		lst = next;
		next = lst -> next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prv;
	int		indexlast;
	int		index;

	if (!*lst)
	{
		new -> index = 1;
		*lst = new;
	}
	else
	{
		ft_printf("%s\n", "TEST1");
		prv = ft_lstlast(*lst);
		ft_printf("%s\n", "TEST2");
		prv -> next = new;
		new -> prev = prv;
		indexlast = prv -> index;
		index = indexlast + 1;
		new -> index = index;
	}
}

void	ft_lstprint(t_list *lst)
{
	t_list	*next;

	if (lst == NULL)
		return ;
	next = lst -> next;
	ft_printf("%d\n", lst->content);
	while (next != NULL && lst -> index <= next -> index)
	{
		lst = next;
		next = lst -> next;
		ft_printf("%d\n", lst->content);
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
	sasb(lst);
	pa(lst, &lst2);
	ft_lstprint(lst2);
	ft_exit(lst, "End of program");
}
