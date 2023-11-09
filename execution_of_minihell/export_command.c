/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/08 21:44:29 by momihamm         ###   ########.fr       */
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

char	*ft_cpyout(char *dst, char *src, char out)
{
	int	indx_i;
	int	indx_j;

	indx_i = 0;
	indx_j = 0;
	while (src[indx_i])
	{
		if (src[indx_i] == out)
		{
			indx_i++;
			if (src[indx_i] == '\0')
			{
				dst[indx_j] = '\0';
				return (dst);
			}
		}
		dst[indx_j] = src[indx_i];
		indx_i++;
		indx_j++;
	}
	dst[indx_j] = '\0';
	return (dst);
}

int	how_mane_plus(char *str, char c)
{
	int indx;
	int cont;

	indx = 0;
	cont = 0;
	while (str[indx])
	{
		// if (str[indx] == c)
		// 	return (cont);
		if (str[indx] == c)
			cont++;
		indx++;
	}
	return (cont);
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

int is_valid(char *str)
{
	char	*key;
	char	*val;
	int		indx;

	key = NULL;
	val = NULL;
	indx = 0;
	key = ft_frontcpy (key, str, '=');
	val = ft_backcpy (val, str, '=');
	while (key[indx])
	{
		if (key[indx] == '+')
			indx++;
		if (ft_isalpha (key[indx]) == 1 && ft_isalpha (key[indx]) == 0)
			return (1);
		indx++;
	}
	return (0);
}

t_node	*make_expo(char *exp)
{
	t_node *new = malloc (sizeof (t_node));

	if (!exp)
		return (NULL);
	if (is_valid (exp) == 1)
	{
		printf ("$$|%s\n",exp);
		return (NULL);
	}
	else
	{
		new->key = NULL;
		new->value_of_the_key = NULL;
		new->plus = 0;
		new->equl = 0;
		if (is_ther_the_win_char (exp, '+', ft_strlen (exp)) == 0 && is_ther_the_win_char (exp, '=', ft_strlen (exp)) == 0)
		{
			// printf ("tajin\n");
			new->key = ft_frontcpy (new->key, exp, '\0');
			printf ("%s\n",new->key);
		}
		else if (is_ther_the_win_char (exp, '+', ft_len (exp, '=')) == 1)
		{
			new->plus = 1;
			new->key = ft_frontcpy (new->key, exp, '=');
			// printf("~~~~~~%s~~~~%d~\n",new->key, how_mane_plus (new->key, '+'));
			new->value_of_the_key = ft_backcpy (new->value_of_the_key, exp, '=');
			if (how_mane_plus (new->key, '+') > 1)
				printf (" export: `%s': not a valid identifier\n",exp);
			else
				take_out (new->key);
			printf ("[%s]\n[%s]\n",new->key, new->value_of_the_key);
		}
		else if (is_ther_the_win_char (exp, '+', ft_len (exp, '=')) == 0)
		{
			// printf ("kmi\n");
			new->equl = 1;
			new->key = ft_frontcpy (new->key, exp, '=');
			new->value_of_the_key = ft_backcpy (new->value_of_the_key, exp, '=');
			printf ("{%s}\n{%s}\n((%s))\n",new->key, new->value_of_the_key,exp);
		}
		new->next = NULL;
		return (new);
	}
}

void    export_command(t_node **my_env, char **arg)
{
	(void) my_env;
	t_node	*usfull;
	t_node	*last;
	int		row;

	row = 0;
	while (arg[row])
	{
		printf ("<<%s>>\n",arg[row]);
		usfull = make_expo (arg[row]);
		// printf ("k???%s?\nv|||%s||\n",usfull->key, usfull->value_of_the_key);
		if (check_is_exist (my_env, usfull->key) == 0)
		{
			last = ft_lstlast (my_env);
			last->next = usfull;
		}
		row++;
	}
	print_export (my_env);
}
