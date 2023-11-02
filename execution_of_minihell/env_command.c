/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:46:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/02 16:17:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

int ft_len(char const *str, char c)
{
	int len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	*ft_frontcpy(char *dst, const char *src, char del)
{
	int	indx;

	indx = 0;
	if (!dst)
		dst = ft_calloc (ft_len (src, del) + 1, sizeof (char));
	while (src[indx] && src[indx] != del)
	{
			dst[indx] = src[indx];
			indx++;
	}
	dst[indx] = '\0';
	return (dst);
}

char	*ft_backcpy(char *dst, const char *src, char del)
{
	int	indx;
	int indj;

	indx = 0;
	indj = 0;
	if (!dst)
		dst = ft_calloc (ft_len (src, del) + 1, sizeof (char));
	while (src[indx] && src[indx] != del)
		indx++;
	if (src[indx] == del)
	{
		indx++;
		while (src[indx] != '\0')
		{
				dst[indj] = src[indx];
				indx++;
				indj++;
		}
		dst[indj] = '\0';
	}
	return (dst);
}

t_node	**take_env(char **env)
{
	t_node **list;
    int	row;

	list = malloc (sizeof (t_node *));
	(*list) = NULL;
	row = 0;
	while (env[row])
	{
		ft_lstadd_back (list, ft_lstnew (env[row]));
		row++;
	}
	return (list);
}

void	print_list(t_node **list)
{
	t_node *ptr;

	ptr = (*list);
	while (ptr)
	{
		printf ("%s=%s\n", ptr->key, ptr->value_of_the_key);
		ptr = ptr->next;
	}
}

// void    env_command(t_node **my_env)
// {
//     int row;

//     row = 0;
//     while (env[row])
//         printf ("%s\n",env[row++]);
// }