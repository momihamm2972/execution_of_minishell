/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:12:09 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/01 13:01:18 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void    my_pdw(void)
{
    // char *buff = NULL;
    // int len = 0;

    // buff = malloc (1);
    // buff = ft_strdup ("");
    printf ("%s\n",getcwd (NULL, 0));
    // len = ft_strlen (buff);
    // printf (">>=%d\n",len);
    // printf ("%s\n",buff);
}