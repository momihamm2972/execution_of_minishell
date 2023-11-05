/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/05 21:59:54 by momihamm         ###   ########.fr       */
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
    t_node **kmya;
    kmya = take_env (env);
    // env_command (env);
    // t_node **kmi =take_env (env);
    // (void) kmi;
    export_command (kmya, "kmya");
    export_command (kmya, "kmya");
    export_command (kmya, "kmya");
    export_command (kmya, "kmya");
    export_command (kmya, "kmya");
    ft_free_contnue (kmya);
    ft_free_list (kmya);
    // t_node *wiwi = ft_lstnew ("kmaya");
    // printf (">>%s<<\n",wiwi->value_of_the_key);
}