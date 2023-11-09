/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/09 13:36:38 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    mr()
{
    system ("leaks minihell");
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    (void) env;
    // atexit(mr);
    // t_node **kmya;
    // kmya = take_env (env);
    // env_command (env);
    // t_node **kmi =take_env (env);
    // (void) kmi;
    // expo    rt_command (kmya, "kmya");
    // export_command (kmya, "kmya+=1337");
    // export_command (kmya, "kmya+=1337");
    // export_command (kmya, "kmya+=55252");
    // export_command (kmya, "kmya+=++++++6639");
    // export_command (kmya, "kmya+=1337");
    // export_command (kmya, "kmya+=lv");
    // ft_free_contnue (kmya);
    // ft_free_list (kmya);
    // t_node *wiwi = ft_lstnew ("kmaya");
    // printf (">>%s<<\n",wiwi->value_of_the_key);
    printf ("%p\n", make_expo("tab+blb+=i3a=hello"));
    // key = "tab+blb+\0"; 
    // value = "i3a=hello\0"
    printf ("%p\n", make_expo("b=world"));
    printf ("%p\n", make_expo("c=coocoo"));
    // printf ("%p\n", make_expo("c"));
    // print_export ()
    // printf ("%p\n", make_expo("kmya"));
    // char **mimi = ft_split ("kmya+=++++++6639 ", ' ');
    // export_command (kmya, mimi);
}