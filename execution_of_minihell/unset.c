/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:50 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/11 21:42:52 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    unset_command(t_node **env, char *str)
{
    t_node  *ptr;
    t_node  *set;
    t_node  *rm;
    // t_node  *prev;
    // t_node  *;

    ptr = (*env);
    if (ft_strcmp (ptr->key, str) == 0)
    {
        printf ("lkmaya########################  <%s>\n", ptr->key);
        rm = ptr;
		printf ("||||||||||||||||||||  <%s>\n",rm->key);
        (*env) = ptr->next;
		printf ("(((((((((((((%s)))))))))))))\n", (*env)->key);
        free(rm->key);
        free(rm->value_of_the_key);
        free (rm);
        print_export (env);
        return ;
    }
    // ptr = ptr->next;
    while (ptr->next)
    {
        if (ft_strcmp (ptr->next->key, str) == 0)
        {
            rm = ptr->next;
			if (rm->next != NULL)
				ptr->next = NULL;
			if (ptr->next)
			{
            	set = ptr->next->next;
				
			}
			if (ptr->next)
            	printf ("*********************kmi********************   <%s>  \n",ptr->next->value_of_the_key);
            // set = ptr;
			if (ptr->next &&  set)
            	ptr->next = set;
				printf ("@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            free(rm->key);
            free(rm->value_of_the_key);
            free (rm);
            print_export (env);
			// return ;
        }
		printf("oui\n");
        ptr = ptr->next;
		printf("no\n");
    }
}
