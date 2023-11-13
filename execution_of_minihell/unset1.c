/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:24:23 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/13 17:26:23 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void	unset_out_error(char *str)
{
	printf (" unset: `%s': not a valid identifier\n", str);
}

int	unset_error(char *test)
{
	int	indx;

	indx = 0;
	if (is_num_sp (test[indx]) == 1)
	{
		unset_out_error (test);
		return (1);
	}
	while (test[++indx])
	{
		if (whitout_plus(test[indx]) == 2)
		{
			if (test[indx + 1] != '\0')
			{
				unset_out_error (test);
				return (1);
			}
		}
		else if (whitout_plus(test[indx]) == 1)
		{
			unset_out_error (test);
			return (1);
		}
	}
	return (0);
}
