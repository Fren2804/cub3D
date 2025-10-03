/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user1 <user1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:34:48 by mvassall          #+#    #+#             */
/*   Updated: 2025/02/26 10:31:09 by user1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_words(char const *s, char sep)
{
	int				in_word;
	unsigned int	counter;

	if (s == NULL)
		return (0);
	in_word = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (!in_word && (*s != sep))
			counter++;
		in_word = (*s++ != sep);
	}
	return (counter);
}

static int	dup_field(char const *src, unsigned int len, char **slot)
{
	char	*dup;

	dup = ft_calloc(len + 1, sizeof(char));
	if (dup == NULL)
		return (0);
	*slot = (char *)ft_memcpy(dup, src, len);
	return (1);
}

static int	split_fields(char const *src, char sep, char **fields)
{
	int				in_word;
	unsigned int	i_field;
	char const		*fb;

	i_field = 0;
	in_word = 0;
	fb = NULL;
	while (*src != '\0')
	{
		if (!in_word && (*src != sep))
			fb = src;
		if (in_word && (*src == sep))
		{
			if (!dup_field(fb, src - fb, fields + i_field))
				return (0);
			i_field++;
			fb = NULL;
		}
		in_word = (*src++ != sep);
	}
	if (fb != NULL)
		return (dup_field(fb, src - fb, fields + i_field));
	return (1);
}

void	*ft_dispose_split(char **fields)
{
	char	**p;

	p = fields;
	while (*p != NULL)
	{
		free(*p++);
	}
	free(fields);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**fields;
	unsigned int	n_words;

	if (s == NULL)
		return (NULL);
	n_words = count_words(s, c);
	fields = ft_calloc(n_words + 1, sizeof(char **));
	if (fields == NULL)
		return (NULL);
	if (!split_fields(s, c, fields))
		return (ft_dispose_split(fields));
	return (fields);
}
