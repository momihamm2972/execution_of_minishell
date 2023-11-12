/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/12 18:19:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    ft_free_only_one_node(t_node *node)
{
    free (node->key);
    free (node->value_of_the_key);
    free (node);
}

void    uneset_head(t_node **env, char *str)
{
    t_node *ptr;
    t_node *ptr;

    ptr = (*env);
    if (ptr && ft_strcmp (ptr->key, str) == 0)
}

void    unset_command(t_node **env, char *str)
{
    t_node  *ptr;
    t_node  *rm;

    ptr = (*env);
    uneset_head(env, str);
    while (ptr)
    {
        if (ptr->next && ft_strcmp (ptr->next->key, str) == 0)
        {
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
