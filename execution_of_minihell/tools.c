/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:39:13 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/16 17:08:15 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	indx;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	indx = 0;
	while (indx < (count * size))
		str[indx++] = 0;
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *to, const void *from, size_t len)
{
	char	*to0;
	char	*from0;
	size_t	i;

	if (!to && !from)
		return (NULL);
	to0 = (char *)to;
	from0 = (char *)from;
	i = 0;
	while (i < len)
	{
		to0[i] = from0[i];
		i++;
	}
	return (to0);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				indx;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (-2147483648);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	indx = 0;
	while (str1[indx] || str2[indx])
	{
		if (str1[indx] != str2[indx])
			return (str1[indx] - str2[indx]);
		indx++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	size_t	indx_of_conca;
	char	*buff;
	size_t	indx;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	indx_of_conca = 0;
	buff = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!buff)
		return (NULL);
	indx = 0;
	while (s1[indx] != '\0')
	{
		buff[indx] = str1[indx];
		indx++;
	}
	while (indx < (ft_strlen(str1) + ft_strlen(str2)))
		buff[indx++] = str2[indx_of_conca++];
	buff[indx] = '\0';
	return (buff);
}
