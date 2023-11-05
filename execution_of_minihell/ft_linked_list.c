/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:45:30 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/05 21:58:44 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

t_node	*ft_lstnew(char *env_val)
{
	(void) env_val;
	t_node	*head;

	head = malloc (sizeof (t_node));
	head->key = NULL;
	head->value_of_the_key = NULL;
	head->key = ft_frontcpy (head->key, env_val, '=');
	head->value_of_the_key = ft_backcpy (head->value_of_the_key, env_val, '=');
	head->next = NULL;
	return (head);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = (*lst);
	(*lst) = new;
}

int	ft_lstsize(t_node *lst)
{
	t_node	*ptr;
	int		i;

	ptr = lst;
	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

t_node	*ft_lstlast(t_node **lst)
{
	t_node	*ptr;

	if (!(*lst))
		return (NULL);
	if ((*lst)->next == NULL)
		return ((*lst));
	ptr = (*lst);
	while (ptr)
	{
		if (ptr->next == NULL)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*the_last;
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}

	the_last = ft_lstlast(lst);
	the_last->next = new;
}
