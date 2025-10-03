/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:36:15 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/06 12:41:16 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*pb;
	const char	*pe;
	char		*str;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	pb = s1;
	while (*pb != '\0' && ft_strchr(set, *pb) != NULL)
		pb++;
	if (*pb == '\0')
		return (ft_calloc(1, sizeof(char)));
	pe = s1 + (ft_strlen(s1) - 1);
	while (pe > pb && ft_strchr(set, *pe) != NULL)
		pe--;
	len = pe - pb + 2;
	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, pb, len);
	return (str);
}
