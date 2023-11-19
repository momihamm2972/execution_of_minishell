/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:25:08 by momihamm          #+#    #+#             */
/*   Updated: 2023/11/19 16:48:59 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_excu.h"

void	free_all(char **s, int ptrs)
{
	int	indx;

	indx = 0;
	while (indx < ptrs)
	{
		free (s[indx]);
		indx++;
	}
	free(s);
}

int	num_of_word(char *s, char c)
{
	int		indx;
	int		len;

	indx = 0;
	len = 0;
	if (s[indx] == '\0')
		return (0);
	while (s[indx])
	{
		if (s[indx] != c)
		{
			len++;
			while (s[indx] != c && s[indx])
				indx++;
			indx--;
		}
		indx++;
	}
	return (len);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*alloc_adds;
	size_t	str_len;
	size_t	indx;
	size_t	end;

	if (!s)
		return (NULL);
	str_len = ft_strlen (s);
	if (start >= str_len)
		return (ft_calloc (1, sizeof(char)));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	alloc_adds = (char *) ft_calloc(len + 1, sizeof (char));
	if (!alloc_adds)
		return (NULL);
	indx = 0;
	end = start + len;
	while (start < end && indx < len + 1 && s[start])
		alloc_adds[indx++] = s[start++];
	return (alloc_adds);
}

char	**ft_split(char *s, char c)
{
	char	**spl;
	int		r_s_e_c[4];

	if (!s)
		return (NULL);
	r_s_e_c[0] = -1;
	r_s_e_c[1] = 0;
	r_s_e_c[2] = 0;
	r_s_e_c[3] = num_of_word((char *)s, c);
	spl = (char **) ft_calloc ((r_s_e_c[3] + 1), sizeof(char *));
	if (!spl)
		return (NULL);
	while (++r_s_e_c[0] < r_s_e_c[3])
	{
		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] == c)
			r_s_e_c[2]++;
		r_s_e_c[1] = r_s_e_c[2];
		while (s[r_s_e_c[2]] && s[r_s_e_c[2]] != c)
			r_s_e_c[2]++;
		spl[r_s_e_c[0]] = ft_substr(s, r_s_e_c[1], (r_s_e_c[2] - r_s_e_c[1]));
		if (!spl[r_s_e_c[0]])
			return (free_all(spl, r_s_e_c[3]), NULL);
		r_s_e_c[1] = r_s_e_c[2];
	}
	return (spl);
}
