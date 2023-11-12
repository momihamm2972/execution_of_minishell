/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/13 00:50:18 by momihamm         ###   ########.fr       */
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

void    unset_command(t_node **env, char **str)
{
    t_node  *ptr;
    t_node  *rm;
    int     row;

    row = 0;
    while (str[row])
    {
        ptr = (*env);
        if (uneset_head(env, str[row]) == 1)
        {
            printf ("***************************\n");
            // ptr = (*env);
        }
        else
        {
            while (ptr)
            {
                // if (unset_error (str[row]) == 1)
                //     break;
                // printf ("<%s>\n", str[row]);
                if (ptr->next && ft_strcmp (ptr->next->key, str[row]) == 0)
                {
                    printf ("<%s>           <%s>\n", ptr->key,str[row]);
                    rm = ptr->next;
                    if (rm->next == NULL)
                    {
                        ptr->next = NULL;
                        ft_free_only_one_node (rm);
                        return ;
                    }
                    ft_free_only_one_node (rm);
                    ptr->next = ptr->next->next;
                }
                ptr = ptr->next;
            }
        }
        row++;
    }
}
