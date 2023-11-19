/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:41:48 by fluchten          #+#    #+#             */
/*   Updated: 2023/11/19 16:50:58 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Return the length of a string */
static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/* Check if there is a new line in the stash */
int	ft_is_newline(char *stash)
{
	size_t	i;

	i = 0;
	if (stash)
	{
		while (stash[i])
		{
			if (stash[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

/* Free the memory and return null */
char	*ft_free_stash(char **stash)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

/* Concatenate two strings allocated with malloc */
char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*join;

	size = ft_strlen(stash) + ft_strlen(buffer);
	if (!size)
		return (ft_free_stash(&stash));
	join = malloc(sizeof(char) * (size + 1));
	if (!join)
		return (ft_free_stash(&stash));
	i = 0;
	j = 0;
	if (stash)
	{
		while (stash[i] && j < size)
			join[j++] = stash[i++];
	}
	i = 0;
	while (buffer[i] && j < size)
		join[j++] = buffer[i++];
	join[j] = '\0';
	free(stash);
	return (join);
}
