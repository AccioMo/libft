/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:47:41 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/03 21:44:34 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	is_sep(const char *s, char c)
{
	if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		return (1);
	else
		return (0);
}

int	count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (is_sep(s, c))
			words++;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	i = 0;
	words = count_words(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char*));
	if (!tab)
		return (NULL);
	tab[words] = NULL;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			if (is_sep(s, c))
			{
				*tab = ft_substr(s + 1 - i, 0, i);
				tab++;
				i = 0;
			}
		}
		s++;
	}
	return (tab - words);
}
