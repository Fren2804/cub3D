/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:54:38 by mvassall          #+#    #+#             */
/*   Updated: 2025/07/04 17:10:00 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_array_len(void **ptrarray)
{
	int	i;

	if (ptrarray == NULL)
		return (0);
	i = 0;
	while (ptrarray[i] != NULL)
		i++;
	return (i);
}

void	**ptr_array_append(void **ptrarray, void *ptr)
{
	void	**aux;
	int		i;

	if (ptr == NULL)
		return (ptrarray);
	if (ptrarray == NULL || *ptrarray == NULL)
	{
		if (ptrarray != NULL && *ptrarray == NULL)
			free(ptrarray);
		ptrarray = ft_calloc(2, sizeof(void *));
		ptrarray[0] = ptr;
		return (ptrarray);
	}
	aux = ft_calloc(ptr_array_len(ptrarray) + 2, sizeof(void *));
	if (aux == NULL)
		return (NULL);
	i = -1;
	while (ptrarray[++i] != NULL)
		aux[i] = ptrarray[i];
	aux[i] = ptr;
	free(ptrarray);
	return (aux);
}

void	ptr_array_freeall(void **ptrarray)
{
	int	i;

	if (ptrarray == NULL)
		return ;
	i = -1;
	while (ptrarray[++i] != NULL)
		free(ptrarray[i]);
	free(ptrarray);
}
