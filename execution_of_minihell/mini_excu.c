/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/02 16:33:25 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;
    // ag
    // printf ("%s",av[1]);
    // my_pdw();
    // my_echo_n ("test");
    // env_command (env);
    // exp_command (list_exp);
    // char m[] = "USER=momihamm";
    // char f[1024];
    // ft_backcpy (f,m,'=');
    // printf ("%s", f);
    // t_node **kmi = take_env(env);
    // print_list (kmi);
    // t_node *_3ezi = ft_lstnew ("togomori=japan\n");
    t_node *_3ezi = ft_lstnew (env[1]);
    printf ("key==>%s\n",_3ezi->key);
    // printf ("val==>%s\n", _3ezi->value_of_the_key);
}