/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/13 16:50:19 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    unset_out_error(char *str)
{
    printf (" unset: `%s': not a valid identifier\n", str);
}

int	unset_error(char *test)
{
	int	indx;

	indx = 0;
	if (is_num_sp (test[indx]) == 1)
	{
		unset_out_error (test);
		return (1);
	}
	while (test[++indx])
	{
		if (whitout_plus(test[indx]) == 2)
		{
			if (test[indx + 1] != '\0')
			{
				unset_out_error (test);
				return (1);
			}
		}
		else if (whitout_plus(test[indx]) == 1)
		{
			unset_out_error (test);
			return (1);
		}
	}
	return (0);
}


void    ft_free_only_one_node(t_node *node)
{
    free (node->key);
    free (node->value_of_the_key);
    free (node);
}

int uneset_head(t_node **env, char *str)
{
    t_node *ptr;
    t_node *rm;

    ptr = (*env);
    if (ptr && ft_strcmp (ptr->key, str) == 0)
    {
        rm = ptr;
        (*env) = ptr->next;
        ft_free_only_one_node (rm);
        return (0);
    }
    return (1);
}

int	empty_list(t_node **list)
{
	if (!(*list))
		return (1);
	return (0);
}

void    unset_command(t_node **env, char **str)
{
    t_node  *ptr;
    t_node  *rm;
    int     row;

    row = 0;
    while (str[row])
    {
        if (uneset_head(env, str[row]) == 0)
        {
            printf ("***************************\n");
            ptr = (*env);
        }
        else
        {
            ptr = (*env);
            while (ptr)
            {
                if (ptr->next && ft_strcmp (ptr->next->key, str[row]) == 0)
                {
                    printf ("<%s>           <%s>\n", ptr->next->key,str[row]);
                    rm = ptr->next;
                    if (rm->next == NULL)
                    {
                        ptr->next = NULL;
                        ft_free_only_one_node (rm);
                        break ;
                    }
                    ptr->next = ptr->next->next;
                    ft_free_only_one_node (rm);
                }
                ptr = ptr->next;
            }
        }
        row++;
    }
    // print_export (env);
	if (empty_list (env) == 1)
		free (env);
}
