/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/03 21:29:33 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    wher_i_am(t_node **my_env)
{
    t_node  *ptr;
    int     current;

    ptr = (*my_env);
    current = 0;
    while (ptr)
    {
        ptr->perv_position = current;
        current++;
        ptr = ptr->next;
    }
}

// void    export_command(t_node **my_env)
// {
    
// }