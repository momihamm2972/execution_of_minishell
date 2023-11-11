/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:22:37 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/11 15:58:43 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

// void	print_export(t_node **list)
// {
// 	t_node	*ptr;

// 	ptr = (*list);
// 	while (ptr)
// 	{
// 		printf ("declare -x %s", ptr->key);
// 		if (ptr->value_of_the_key != NULL)
// 			printf ("=%c%s%c", 34, ptr->value_of_the_key, 34);
// 		printf ("\n");
// 		ptr = ptr->next;
// 	}
// }

// char	*ft_frontcpy_p(char *dst, char *src, char del)
// {
// 	int	indx;

// 	indx = 0;
// 	if (!dst)
// 		dst = ft_calloc (ft_len (src, del) + 1, sizeof (char));
// 	while (src[indx] && src[indx] != del)
// 	{
// 		dst[indx] = src[indx];
// 		indx++;
// 	}
// 	dst[indx] = '\0';
// 	return (dst);
// }

// void	swap_nodes(t_node **my_env)
// {
// 	t_node	*ptr;
// 	char	*swp0;
// 	char	*swp1;

// 	ptr = (*my_env);
// 	swp0 = NULL;
// 	swp1 = NULL;
// 	while (ptr)
// 	{
// 		if (ptr && ptr->next && ft_strcmp (ptr->key, ptr->next->key) > 0)
// 		{
// 			swp0 = ptr->key;
// 			swp1 = ptr->value_of_the_key;
// 			ptr->key = ptr->next->key;
// 			ptr->value_of_the_key = ptr->next->value_of_the_key;
// 			ptr->next->key = swp0;
// 			ptr->next->value_of_the_key = swp1;
// 			ptr = (*my_env);
// 		}
// 		else
// 			ptr = ptr->next;
// 	}
// }

// t_node	*check_is_exist(t_node **list, char *var)
// {
// 	t_node	*ptr;

// 	ptr = (*list);
// 	while (ptr)
// 	{
// 		if (ft_strcmp (ptr->key, var) == 0)
// 			return (ptr);
// 		ptr = ptr->next;
// 	}
// 	return (NULL);
// }

// void	take_out(char *str)
// {
// 	int	indx;

// 	indx = 0;
// 	while (str[indx])
// 	{
// 		if (str[indx] == '+')
// 		{
// 			str[indx] = '\0';
// 			return ;
// 		}
// 		indx++;
// 	}
// }

// t_node	*take_key_vlu(char *str)
// {
// 	t_node	*new;

// 	new = ft_lstnew (str);
// 	return (new);
// }

// int	is_num_sp(char c)
// {
// 	if ((c >= 33 && c <= 64) || (c >= 91 && c <= 94)
// 		|| c == 96 || (c >= 123 && c <= 126))
// 		return (1);
// 	return (0);
// }

// int	whitout_plus(char c)
// {
// 	if (c == 43)
// 		return (2);
// 	if ((c >= 33 && c <= 42) || (c >= 44 && c <= 47) || (c >= 58 && c <= 64)
// 		|| (c >= 91 && c <= 94) || c == 96 || (c >= 123 && c <= 126))
// 		return (1);
// 	return (0);
// }

// void	error_export(char *key, char *val)
// {
// 	printf (" export: `%s", key);
// 	if (val)
// 		printf("=%s': not a valid identifier\n", val);
// 	else
// 		printf ("': not a valid identifier\n");
// }

// int	key_error(t_node *test)
// {
// 	int	indx;

// 	indx = 0;
// 	if (is_num_sp (test->key[indx]) == 1)
// 	{
// 		error_export (test->key, test->value_of_the_key);
// 		return (1);
// 	}
// 	while (test->key[++indx])
// 	{
// 		if (whitout_plus(test->key[indx]) == 2)
// 		{
// 			if (test->key[indx + 1] != '\0')
// 			{
// 				error_export (test->key, test->value_of_the_key);
// 				return (1);
// 			}
// 		}
// 		else if (whitout_plus(test->key[indx]) == 1)
// 		{
// 			error_export (test->key, test->value_of_the_key);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// int	how_alpha(char *str)
// {
// 	int	indx;
// 	int	cont;

// 	indx = 0;
// 	cont = 0;
// 	while (str[indx])
// 	{
// 		if (str[indx] == 95 && str[indx + 1] != '\0')
// 			cont++;
// 		if (ft_isalpha (str[indx]) == 1 || ft_isdigit (str[indx]) == 1)
// 			cont++;
// 		indx++;
// 	}
// 	return (cont);
// }

// int	is_ther_plus(char *str)
// {
// 	int	indx;

// 	indx = 0;
// 	while (str[indx])
// 	{
// 		if (str[indx] == '+')
// 			return (1);
// 		indx++;
// 	}
// 	return (0);
// }

// void	make_out(t_node *node)
// {
// 	node->plus = 1;
// 	take_out (node->key);
// }

// int	is_equal(char *str)
// {
// 	int	indx;

// 	indx = 0;
// 	while (str[indx])
// 	{
// 		if (str[indx] == '=')
// 			return (1);
// 		indx++;
// 	}
// 	return (0);
// }

// void	export_remplass(t_node *list, t_node *one)
// {
// 	char	*ptr;

// 	ptr = list->value_of_the_key;
// 	list->value_of_the_key = one->value_of_the_key;
// 	free (ptr);
// 	free (one->key);
// 	free (one);
// }

// void	remplace(t_node *list, t_node *one)
// {
// 	if (one->equl == 1 && one->plus == 0)
// 		export_remplass (list, one);
// 	else
// 	{
// 		ft_free_contnue (&one);
// 		free (one);
// 	}
// }

// void	export_conca(t_node *list, t_node *one)
// {
// 	char	*ptr;

// 	ptr = list->value_of_the_key;
// 	list->value_of_the_key = ft_strjoin
// 		(list->value_of_the_key, one->value_of_the_key);
// 	free (ptr);
// 	ft_free_contnue (&one);
// 	free (one);
// }

// void	take_last_link(t_node **env, t_node *new)
// {
// 	t_node	*last;

// 	last = ft_lstlast (env);
// 	last->next = new;
// }

// void	check_link(t_node **my_env, t_node *new)
// {
// 	t_node	*an_node;

// 	if (!my_env || !new)
// 		return ;
// 	if (key_error (new) == 0)
// 	{
// 		if (is_ther_plus (new->key) == 1)
// 			make_out (new);
// 		an_node = check_is_exist (my_env, new->key);
// 		if (an_node != NULL)
// 		{
// 			if (new->plus == 1)
// 				export_conca (an_node, new);
// 			else
// 				remplace (an_node, new);
// 		}
// 		else
// 			take_last_link(my_env, new);
// 	}
// 	else
// 	{
// 		ft_free_contnue (&new);
// 		free (new);
// 	}
// }

// int	check_nil(t_node **env, char **matrix)
// {
// 	if (!matrix)
// 	{
// 		swap_nodes (env);
// 		print_export (env);
// 		return (1);
// 	}
// 	return (0);
// }

void	intial(t_node *new, char *str)
{
	new = ft_lstnew (str);
	if (is_equal (str) == 1)
		new->equl = 1;
}

void	export_command(t_node **my_env, char **arg)
{
	t_node	*new;
	int		row;

	row = -1;
	if (check_nil (my_env, arg) == 1)
		return ;
	while (arg[++row])
	{
		new = ft_lstnew (arg[row]);
		if (is_equal (arg[row]) == 1)
			new->equl = 1;
		if (how_alpha (new->key) == 0)
		{
			ft_free_contnue (&new);
			free (new);
			break ;
		}
		if (arg[row][0] == '=')
		{
			printf (" export: `%s': not a valid identifier\n", arg[row]);
			free (new);
			break ;
		}
		check_link (my_env, new);
	}
}
