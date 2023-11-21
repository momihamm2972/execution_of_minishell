/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 02:14:28 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/21 02:49:57 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

char	*add_plus(char *str)
{
	int		indx;
	char	*key;

	indx = 0;
	key = ft_calloc (ft_strlen (str) + 2, sizeof (char));
	while (str[indx])
	{
		if (str[indx + 1] == '\0')
		{
			key[indx] = str[indx];
			key[indx + 1] = '=';
			key[indx + 2] = '\0';
			return (key);
		}
		key[indx] = str[indx];
		indx++;
	}
	return (NULL);
}

char	**make_list_arr(t_node **list)
{
	t_node	*add;
    char	**arr;
	// char	*ptr;
	int		row;

	if (list || (*list))
		return (NULL);
	add = (*list);
	arr = (char **) ft_calloc (ft_lstsize ((*list)), sizeof (char *));
	if (arr)
		return (NULL);
	row = 0;
	while (add)
	{
		arr[row] = ft_strjoin (add_plus(add->key),add->value_of_the_key);
		printf ("<%s>\n", arr[row]);
		add = add->next;
		row++;
	}
	arr[row] = NULL;
	return (arr);
}

void	print_2D(char **arr)
{
	int indx;

	indx = 0;
	while (arr[indx])
	{
		printf ("> %s\n", arr[indx]);
		indx++;
	}
}
