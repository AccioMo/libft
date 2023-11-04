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

int	count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			words++;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;

	while (*s == c)
		s++;
	words = count_words(s, c);
	tab = (char **)malloc(words + 1);
	if (!tab)
		return (NULL);
	tab[words] = "\0";
	while (*s)
	{
		if (*s == c)
		{
			s++;
			printf("l: %ld\n", ft_strchr(s, c) - s);
			*tab = ft_substr(s, 0, ft_strchr(s, c) - s);
			tab++;
		}
		printf("%s\n", *tab);
		s++;
	}
	return (tab - words);
}

int	main(void)
{
	char	**tab;
	int		i;

	tab = ft_split("hello world", ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}