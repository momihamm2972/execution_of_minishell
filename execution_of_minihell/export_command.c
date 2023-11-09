/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/09 19:22:48 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void	print_export(t_node **list)
{
	t_node *ptr;

	ptr = (*list);
	while (ptr)
	{
		printf ("declare -x %s",ptr->key);
		if (ptr->value_of_the_key != NULL)
			printf ("=%c%s%c", 34, ptr->value_of_the_key, 34);
		printf ("\n");
		ptr = ptr->next;
	}
}

char	*ft_frontcpy_p(char *dst, char *src, char del)
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

void    swap_nodes(t_node **my_env)
{
    t_node  *ptr;
    char  *swp0;
    char  *swp1;

    ptr = (*my_env);
    swp0 = NULL;
    swp1 = NULL;
	while (ptr)
	{
		if (ptr && ptr->next && ft_strcmp (ptr->key,ptr->next->key) > 0)
		{
			swp0 = ptr->key;
			swp1 = ptr->value_of_the_key;
			ptr->key = ptr->next->key;
			ptr->value_of_the_key = ptr->next->value_of_the_key;
			ptr->next->key = swp0;
			ptr->next->value_of_the_key = swp1;
			ptr = (*my_env);
			// free (swp0);
			// free (swp1);
		}
		else
			ptr = ptr->next;
	}
}

t_node	*check_is_exist(t_node **list, char *var)
{
	t_node	*ptr;

	ptr = (*list);
	while (ptr)
	{
		if (ft_strcmp (ptr->key, var) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}




void	take_out(char *str)
{
	int indx;

	indx = 0;
	while (str[indx])
	{
		if (str[indx] == '+')
		{
			str[indx] = '\0';
			return ;
		}
		indx++;
	}
}



t_node	*take_key_vlu(char *str)
{
	t_node	*new;

	new = ft_lstnew (str);
	return (new);
}

int	is_num_sp(char c)
{
	if ((c >= 33 && c <= 64) || (c >= 91 && c <= 94)
		|| c == 96 || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

int	whitout_plus(char c)
{
	if (c == 43)
		return (2);
	if ((c >= 33 && c <= 42) || (c >= 44 && c <= 47) || (c >= 58 && c <= 64) ||
		(c >= 91 && c <= 94) || c == 96 || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

void	error_export(char *key, char *val)
{
	printf (" export: `%s",key);
	if (val)
		printf("=%s': not a valid identifier\n", val);
	else
		printf ("': not a valid identifier\n");
}

int	key_error(t_node *test)
{
	int	indx;

	indx = 0;
	if (is_num_sp (test->key[indx]) == 1)
	{
		error_export (test->key, test->value_of_the_key);
		return (1);
	}
	while (test->key[++indx])
	{
		if (whitout_plus(test->key[indx]) == 2)
		{
			if (test->key[indx + 1] != '\0')
			{
				error_export (test->key, test->value_of_the_key);
				return (1);
			}
		}
		else if (whitout_plus(test->key[indx]) == 1)
		{
			error_export (test->key, test->value_of_the_key);
			return (1);
		}
	}
	return (0);
}

int	how_alpha(char *str)
{
	int	indx;
	int	cont;

	indx = 0;
	cont = 0;
	while (str[indx])
	{
		if (ft_isalpha (str[indx]) == 1 || ft_isdigit (str[indx]) == 1)
			cont++;
		indx++;
	}
	return (cont);
}

int	is_ther_plus(char *str)
{
	int indx;

	indx = 0;
	while (str[indx])
	{
		if (str[indx] == '+')
			return (1);
		indx++;
	}
	return (0);
}

void    export_command(t_node **my_env, char **arg)
{
	(void) my_env;
	t_node	*new;
	t_node	*last;
	t_node	*an_node;
	int		row;
	
	row = 0;
	if (!arg)
	{
		swap_nodes(my_env);
		print_export (my_env);
		return ;
	}
	while (arg[row])
	{
		new = take_key_vlu (arg[row]);
		if (how_alpha (new->key) == 0)
			return ;
		if (arg[row][0] == '=')
		{
			printf (" export: `%s': not a valid identifier\n", arg[row]);
			return ;
		}
		if (key_error (new) == 1)
			return ;
		if (is_ther_plus (new->key) == 1)
		{
			// printf ("sami\n");
			new->plus = 1;
			// printf ("B|%s|\n", new->key);
			take_out (new->key);
			// printf ("A|%s|\n", new->key);
		}
		// printf ("N+/%s/\n",new->key);
		an_node = check_is_exist (my_env, new->key);
		if (an_node != NULL)
		{
			printf ("kane\n");
			if (new->plus == 1)
			{
				printf ("B|%s|\n", an_node->value_of_the_key);
				an_node->value_of_the_key = ft_strjoin (an_node->value_of_the_key, new->value_of_the_key);
				printf ("A|%s|\n", an_node->value_of_the_key);
			}
			else
			{
				printf (">A|%s|\n", an_node->value_of_the_key);
				an_node->value_of_the_key = new->value_of_the_key;
				printf (">B|%s|\n", an_node->value_of_the_key);
			}
		}
		else
		{
			printf ("jadid\n");
			last = ft_lstlast (my_env);
			last->next	= new;
		}
		row++;
	}
	printf ("jmil\n");
	// print_export (my_env);
}
