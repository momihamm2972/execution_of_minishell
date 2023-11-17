/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:39:16 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/17 22:18:18 by momihamm         ###   ########.fr       */
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
		printf ("exit\n");
		status = num;
	}
	if (num > 256)
	{
		printf ("exit\n");
		status = num % 256;
		// status = 91;
	}
}

int	num_arg_of_exit(char *str)
{
	long long	arg;

	arg = ft_atoi (str);
	if (arg == -1)
	{
		printf (" exit: %s: numeric argument| required\n", str);
		status = 255;
		return (1);
		// exit (0);
	}
	exit_status (arg);
	return (0);
}

void	ft_exit(char **matrix)
{
	int			row;
	// long long	arg;

	if (!matrix || !matrix[0])
	{
		status = 0;
		printf ("exit\n");
		// exit(0);
		return ;
	}
	row = -1;
	while (matrix[++row])
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
			num_arg_of_exit (matrix[row]);
			// arg = ft_atoi (matrix[row]);
			// if (arg == -1)
			// {
			// 	printf (" exit: %s: numeric argument| required\n", matrix[row]);
			// 	status = 255;
			// 	return ;
			// }
			// exit_status (arg);
		}
	}
}
