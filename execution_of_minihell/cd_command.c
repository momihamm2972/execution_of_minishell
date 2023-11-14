/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:55:19 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/14 19:03:49 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

t_node	*get_node(t_node **list, char *str)
{
	t_node	*ptr;

	ptr = (*list);
	while (ptr)
	{
		if (ft_strcmp (ptr->key, str) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

char	*arg_use(char *str)
{
	char	*re;
	int		indx_i;
	int		indx_j;
	int		len;
	
	indx_i = 0;
	indx_j = 0;
	len = ft_strlen (str);
	re = ft_calloc (len, sizeof (char));
	while (str[indx_i])
	{
		if ((str[indx_i] == '-' || str[indx_i] == '~'))
			indx_i++;
		if (str[indx_i])
			re[indx_j] = str[indx_i];
		indx_i++;
		indx_j++;
	}
	return (re);
}

int	arg_path(char *str)
{
	if (str[0] != '-' && str[0] != '~')
		return (0);
	else if (str[0] == '-')
		return (1);
	else if (str[0] == '~')
	{
		if (str[1] == '\0')
			return (2);
		else
			return (3);
	}
	return (-1);
}

void	place(char *str)
{
	if (str[0] == '~')
		str[0] = '/';
}

void    cd_command (t_node **env, char **arg)
{
	(void) env;
	
	char *ptr;

	printf (">%s<%d>\n",arg[0], arg_path (arg[0]));
    if (arg_path (arg[0]) == 0)
	{
		if (chdir (arg[0]) == 0)
			printf ("**************kmi**********\n");
		else
			printf ("??????????????????????????????????\n");
	}
	else if (arg_path (arg[0]) == 1)
	{
		printf ("*%s*\n",arg_use (arg[0]));
		if (chdir (arg_use (arg[0])) == 0)
			printf ("!!!!!!!!!!!!!!!!!!!!!\n");
		else
			printf ("))))))))))))))))))\n");
	}
	else if (arg_path (arg[0]) == 2)
	{
		printf ("(%s)<%s>\n",arg[0], get_node(env, "HOME")->value_of_the_key);
		if (chdir (get_node(env, "HOME")->value_of_the_key) == 0)
			printf ("@@@@@@@@@@@@@@@@@@@@@@@@\n");
		else
			printf ("^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	else if (arg_path (arg[0]) == 3)
	{
		printf ("(%s&&%s>\n",arg[0], get_node(env, "HOME")->value_of_the_key);
		// place (arg[0]);
		ptr = ft_strjoin (get_node(env, "HOME")->value_of_the_key, "/");
		ptr = ft_strjoin (ptr, arg_use (arg[0]));
		printf ("---%s---\n", ptr);
		if (chdir (ptr) == 0)
			printf ("$$$$$$$$$$$$$$$$$$$$\n");
		else
			printf ("+++++++++++++++++++++++++++\n");
	}
}
