/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkeil <tkeil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:57:08 by tkeil             #+#    #+#             */
/*   Updated: 2024/10/14 12:16:32 by tkeil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memfree(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static char	**ft_strsplitter(char **ptr, char const *s, char c)
{
	char const	*p;
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			p = s;
			while (*s && *s != c)
				s++;
			ptr[i] = ft_substr(p, 0, s - p);
			if (!ptr[i])
				return (NULL);
			i++;
		}
		else
			s++;
	}
	ptr[i] = NULL;
	return (ptr);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	if (!ft_strsplitter(ptr, s, c))
	{
		ft_memfree(ptr);
		return (NULL);
	}
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
//     char *str = "halli hallo";
//     char c = ' ';
//     char **ptr = ft_split(str, c);
//     int i = 0;
//     while (ptr[i] != NULL)
//     {
//         printf("%s\n", ptr[i]);
//         i++;
//     }
//     return (0);
// }