/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzaengel <lzaengel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:12:34 by lzaengel          #+#    #+#             */
/*   Updated: 2023/12/28 20:31:52 by lzaengel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_list *lst, char *reason)
{
	t_list	*next;

	ft_printf ("%s\n", reason);
	if (lst == NULL)
		exit(0);
	while (lst)
	{
		next = lst -> next;
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
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{	
		ft_printf("%d\n", lst->content);
		lst = lst -> next;
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
	int			nbr;

	j = 1;
	lst = 0;
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
	ft_lstprint(lst);
	ft_exit(lst, "End of program");
}
