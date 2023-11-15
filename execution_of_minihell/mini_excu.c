/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_excu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:56:43 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/15 21:17:59 by momihamm         ###   ########.fr       */
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
    // atexit (mr);
    t_node **kmi = take_env (env);
    export_command (kmi, NULL);
    printf ("#####################################################\n");
    char **wi = ft_split (" push ", ' ');
    char **ay = ft_split (" OLDPWD ", ' ');

    unset_command (kmi, ay);
    cd_command (kmi, wi);
    printf ("#####################################################\n");
    export_command (kmi, NULL);
    int word = num_of_word (" push ", ' ');
    free_all (wi, word);
    int a = num_of_word (" OLDPWD ", ' ');
    free_all (ay, a);
    ft_free_contnue (kmi);
    ft_free_list (kmi);
    // while(1);  
}