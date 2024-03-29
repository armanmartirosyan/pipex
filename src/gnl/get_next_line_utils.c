/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armartir <armartir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:56:57 by armartir          #+#    #+#             */
/*   Updated: 2023/03/26 15:42:30 by armartir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	s_len(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		++i;
	return (i);
}

char	*char_n(char *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (ptr + i);
		++i;
	}
	return (0);
}

char	*get_and_clean(char *ptr)
{
	char	*lin;
	int		i;

	i = 0;
	if (!ptr[i])
		return (0);
	while (ptr[i] && ptr[i] != '\n')
		++i;
	lin = malloc((i + 2) * sizeof(char));
	if (!lin)
		return (0);
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
	{
		lin[i] = ptr[i];
		++i;
	}
	if (ptr[i] == '\n')
	{
		lin[i] = ptr[i];
		++i;
	}
	lin[i] = 0;
	return (lin);
}

char	*get_and_clean_ptr(char *ptr)
{
	int		i;
	int		j;
	char	*ptr2;

	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		++i;
	if (!ptr[i])
	{
		free(ptr);
		return (0);
	}
	ptr2 = malloc((s_len(ptr) - i + 1) * sizeof(char));
	if (!ptr2)
		return (0);
	++i;
	j = 0;
	while (ptr[i])
		ptr2[j++] = ptr[i++];
	ptr2[j] = 0;
	free(ptr);
	return (ptr2);
}
