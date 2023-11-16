/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:39:16 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/16 18:48:48 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void	*ft_memmove(void *to, void *from, size_t byte)
{
	char	*dst;
	char	*src;

	if (!to && !from)
		return (NULL);
	dst = (char *) to;
	src = (char *) from;
	if (dst < src)
		ft_memcpy(dst, src, byte);
	else
	{
		while (byte--)
		{
			dst[byte] = src[byte];
		}	
	}
	return (dst);
}

// int	take_byte(int num)
// {
// 	unsigned char	bit;
// 	int				indx;

// 	indx = 0;
// 	while (indx < 7)
// }

int	is_word(char *str)
{
	int	indx;

	indx = 0;
	while (str[indx])
	{
		if (ft_isalpha (str[indx]) == 1)
			return (1);
		indx++;
	}
	return (0);
}

void	exit_status(size_t num)
{
	if (num >=0 && num <= 256)
	{
		printf ("exitY\n");
		status = num;
	}
	if (num > 256)
	{
		printf ("exitM\n");
		status = num % 256;
	}
}

void	ft_exit(char **matrix)
{
	int			row;
	long long	arg;
	long long	max;

	if (!matrix || !matrix[0])
	{
		status = 4587;
		printf ("exit\n");
		// exit(0);
		return ;
	}
	row = 0;
	max = 9223372036854775807;
	while (matrix[row])
	{
		if (is_word (matrix[row]) == 1)
		{
			printf ("exit\n");
			printf (" exit: %s: numeric argument required\n", matrix [row]);
			status = 255;
			return ; 
		}
		else
		{
			printf (":%s:\n",matrix[0]);
			arg = ft_atoi (matrix[row]);
			printf (">%lld<\n", arg);
			if (arg > max)
			{
				printf ("exit\n");
				printf (" exit: %s: numeric argument required\n", matrix [row]);
				status = 255;
				return ;
			}
			printf ("/%lld/\n", arg);
			exit_status (arg);
			printf ("byte<%d>\n", status);
		}
		row++;
	}
}
