/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:04:15 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/18 22:31:08 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

int option(char *str)
{
    int indx;

    if (str[0] != '-' || !str[1])
        return (1);
    // if (!str[1])
    indx = 1;
    while (str[indx])
    {
        if (str[indx] != 'n')
            return (1);
        indx++;
    }
    return (0);
}

int delete_line(char **matrix, int row)
{
    // int row;

    // row = 0;
    if (option(matrix[row]) == 1)
    {
        printf ("\n$$$\n");
        while (matrix [row])
        {
            printf ("%s", matrix[row]);
            if (matrix[row + 1])
                printf (" ");
            if (!matrix[row + 1])
            {
                // printf ("\n");
                return (-1);
            }
            row++;
        }
    }
    return (row);
}

void    my_echo_n(char **argum)
{
    int row;

    if (!argum || !argum[0])
        printf ("\n");
    row = 0;
    
    while (argum[row])
    {
        if (option (argum[row]) == 0)
        {
            // row = delete_line (argum, row);
            // if (row == -1)
            // {
            //     printf ("       1231");
            //     return ;
            // }
            while (argum[row])
            {
                if (option (argum[row]) == 1)
                {
                    printf ("\n$$$\n");
                    while (argum[row])
                    {
                        printf ("%s", argum[row]);
                        if (argum[row + 1])
                            printf (" ");
                        if (!argum[row + 1])
                        {
                                // printf ("\n");
                            return ;
                        }
                        row++;
                    }
                }
                row++;
            }
        }
        else
        {
            printf ("\n***\n");
            while (argum[row])
            {
                printf ("%s", argum[row]);
                if (argum[row + 1])
                    printf (" ");
                row++;
                if (!argum[row])
                {
                    printf ("\n");
                    return ;
                }
            }
        }
        row++;
    }
}
