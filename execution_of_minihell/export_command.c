/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/05 23:49:54 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void	print_export(t_node **list)
{
	t_node *ptr;

	ptr = (*list);
	while (ptr)
	{
		printf ("declare -x %s",ptr->key);
		if (ptr->value_of_the_key != NULL)
			printf ("=%c%s%c", 34, ptr->value_of_the_key, 34);
		printf ("\n");
		ptr = ptr->next;
	}
}

char	*ft_frontcpy_p(char *dst, char *src, char del)
{
	int	indx;

	indx = 0;
	if (!dst)
		dst = ft_calloc (ft_len (src, del) + 1, sizeof (char));
	while (src[indx] && src[indx] != del)
	{
			dst[indx] = src[indx];
			indx++;
	}
	dst[indx] = '\0';
	return (dst);
}

void    swap_nodes(t_node **my_env)
{
    t_node  *ptr;
    char  *swp0;
    char  *swp1;

    ptr = (*my_env);
    swp0 = NULL;
    swp1 = NULL;
	while (ptr)
	{
		if (ptr && ptr->next && ft_strcmp (ptr->key,ptr->next->key) > 0)
		{
			swp0 = ptr->key;
			swp1 = ptr->value_of_the_key;
			ptr->key = ptr->next->key;
			ptr->value_of_the_key = ptr->next->value_of_the_key;
			ptr->next->key = swp0;
			ptr->next->value_of_the_key = swp1;
			ptr = (*my_env);
			// free (swp0);
			// free (swp1);
		}
		else
			ptr = ptr->next;
	}
}

int	check_is_exist(t_node **list, char *var)
{
	t_node	*ptr;

	ptr = (*list);
	while (ptr)
	{
		if (ft_strcmp (ptr->key, var) == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

// char	* make_expo(char *exp)
// {
// 	if (is_ther_the_win_char (exp, '+') == 1)
// 	{
		
// 	}
// }

void    export_command(t_node **my_env, char *arg)
{
    swap_nodes (my_env);
	if (arg)
	{	
		if (check_is_exist(my_env, arg) == 0)
			ft_lstadd_back (my_env, ft_lstnew (arg));
	}
    print_export (my_env);

}
