/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:04:15 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/18 20:29:21 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

int option(char *str)
{
    int indx;

    indx = 1;
    while (str[indx])
    {
        if (str[indx] != 'n')
            return (1);
        indx++;
    }
    return (0);
}

// int new_line(char *str)
// {
//     int	indx;

// 	indx = 1;
// 	while (str[indx])
// 	{
// 		if (str[indx] != 'n')
// 			return (0);
// 		indx++;
// 	}
// 	return (1);
// }

// int an_arg(char *str)
// {
//     int indx;

//     indx = 0;
//     while (str[indx])
// }

// int	is_option_conca_whit_arg(char *str)
// {
// 	int	indx;

// 	indx = 1;
// 	while (str[indx])
// 	{
		
// 	}
// }

void    my_echo_n(char **argum)
{
    int row;
	// int	line;

    if (!argum || !argum[0])
        printf ("\n");
    row = 0;
    
    while (argum[row])
    {
        if (argum[row][0] == '-')
        {
            printf ("\n@@@\n");
			// line = option (argum[0]);
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
						// if (new_line (argum [row]) == 1)
                        	printf ("\n");
                        return ;
                    }
                    row++;
                }
                // printf ("\n");÷
            }
            // else
            // {
            //     row++;
            //     while (argum[row])
            //     {
            //         printf ("%s", argum[row]);
            //         if (argum[row + 1])
            //             printf (" ");
            //         row++;
            //         if (!argum[row])
            //             return ;
            //     }
            // }
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
					// printf ("\n");
                    return ;
				}
            }
        }
        row++;
    }
}