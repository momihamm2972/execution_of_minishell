/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/09 18:02:55 by momihamm         ###   ########.fr       */
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

int	check_is_exist(t_node **list, char *var)
{
	t_node	*ptr;

	ptr = (*list);
	while (ptr)
	{
		if (ft_strcmp (ptr->key, var) == 0)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

// char	*ft_cpyout(char *dst, char *src, char out)
// {
// 	int	indx_i;
// 	int	indx_j;

// 	indx_i = 0;
// 	indx_j = 0;
// 	while (src[indx_i])
// 	{
// 		if (src[indx_i] == out)
// 		{
// 			indx_i++;
// 			if (src[indx_i] == '\0')
// 			{
// 				dst[indx_j] = '\0';
// 				return (dst);
// 			}
// 		}
// 		dst[indx_j] = src[indx_i];
// 		indx_i++;
// 		indx_j++;
// 	}
// 	dst[indx_j] = '\0';
// 	return (dst);
// }

// int	how_mane_plus(char *str, char c)
// {
// 	int indx;
// 	int cont;

// 	indx = 0;
// 	cont = 0;
// 	while (str[indx])
// 	{
// 		// if (str[indx] == c)
// 		// 	return (cont);
// 		if (str[indx] == c)
// 			cont++;
// 		indx++;
// 	}
// 	return (cont);
// }

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

// int is_valid(char *str)
// {
// 	char	*key;
// 	char	*val;
// 	int		indx;

// 	key = NULL;
// 	val = NULL;
// 	indx = 0;
// 	key = ft_frontcpy (key, str, '=');
// 	val = ft_backcpy (val, str, '=');
// 	while (key[indx])
// 	{
// 		if (key[indx] == '+')
// 			indx++;
// 		if (ft_isalpha (key[indx]) == 1 && ft_isalpha (key[indx]) == 0)
// 			return (1);
// 		indx++;
// 	}
// 	return (0);
// }

// t_node	*make_expo(char *exp)
// {

// }

t_node	*take_key_vlu(char *str)
{
	t_node	*new;

	new = ft_lstnew (str);
	return (new);
}

int	is_num_sp(char c)
{
	if ((c >= 33 && c <= 64) || (c >= 91 && c <= 94) || c == 96 || (c >= 123 && c <= 126))
	{
		// printf (">>%c>>%d\n",c,c);
		return (1);
	}
	// printf (">>|\"%c\">>%d\n",c,c);
	return (0);
}

int	whitout_plus(char c)
{
	if (c == 43)
		return (2);
	if ((c >= 33 && c <= 42) || (c >= 44 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 94) || c == 96 || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

int	key_error(t_node *test)
{
	int	indx;

	indx = 0;
	printf ("[%s]\n",test->key);
	if (is_num_sp (test->key[indx]) == 1)
	{
		printf (" export: `%s",test->key);
		if (test->value_of_the_key)
			printf("=%s': not a valid identifier\n", test->value_of_the_key);
		else
			printf ("': not a valid identifier\n");
		return (1);
	}
	indx = 1;
	while (test->key[indx])
	{
		if (whitout_plus(test->key[indx]) == 2)
		{
			// printf ("hx\n");
			if (test->key[indx + 1] != '\0')
			{
				printf (" export: `%s",test->key);
				if (test->value_of_the_key)
					printf("=%s': not a valid identifier\n", test->value_of_the_key);
				else
					printf ("': not a valid identifier\n");
				return (1);
			}
		}
		else if (whitout_plus(test->key[indx]) == 1)
		{
			printf (" export: `%s",test->key);
			if (test->value_of_the_key)
				printf("=%s': not a valid identifier\n", test->value_of_the_key);
			else
				printf ("': not a valid identifier\n");
			return (1);
		}
		indx++;
	}
	// atleast one char;
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

void    export_command(t_node **my_env, char **arg)
{
	t_node	*new;
	int		row;
	
	row = 0;
	while (arg[row])
	{
		
		printf ("<%s>\n",arg[row]);
		new = take_key_vlu (arg[row]);
		if (how_alpha (new->key) == 0)
		{
			printf ("rewicha\n");
			return ;
		}
		if (arg[row][0] == '=')
		{
			printf (" export: `%s': not a valid identifier\n", arg[row]);
			return ;
		}
		if (key_error (new) == 1)
			return ;
		row++;
	}
	printf ("jmil\n");
	// print_export (my_env);
}
