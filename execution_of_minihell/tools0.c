/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:54:27 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/17 18:53:55 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	over_flow(long long num)
{
	return (num);
}

// long long	ft_atoi(const char *str)
// {
// 	int			i;
// 	int			s;
// 	long long	r;

// 	i = 0;
// 	r = 0;
// 	s = 1;
// 	while (str[i] != '\0')
// 	{
// 		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 			i++;
// 		if (str[i] == '-' || str[i] == '+' )
// 		{
// 			if (str[i] == '-' )
// 				s = -1;
// 			i++;
// 		}
// 		if (!(str[i] >= '0' && str[i] <= '9'))
// 			return (0);
// 		r = (r * 10) + str[i] - '0';
// 		i++;
// 		if ((str[i] >= 0 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 127))
// 			break ;
// 	}
// 	return (r * s);
// }

long long	ft_atoi(char *str)
{
	unsigned	long long	i_r_s[4];

	i_r_s[0] = -1;
	i_r_s[1] = 0;
	i_r_s[2] = 1;
	i_r_s[3] = -1;
	while (str[++i_r_s[0]] != '\0')
	{
		while (str[i_r_s[0]] == 32
			|| (str[i_r_s[0]] >= 9 && str[i_r_s[0]] <= 13))
			i_r_s[0]++;
		if (str[i_r_s[0]] == '-' || str[i_r_s[0]] == '+' )
		{
			if (str[i_r_s[0]] == '-' )
				i_r_s[2] = -1;
			i_r_s[0]++;
		}
		if (!(str[i_r_s[0]] >= '0' && str[i_r_s[0]] <= '9'))
			return (0);
		i_r_s[1] = (i_r_s[1] * 10) + str[i_r_s[0]] - '0';
		if ((i_r_s[1]) > 9223372036854775807)
			return (i_r_s[3]);
	}
	return (i_r_s[1] * i_r_s[2]);
}
