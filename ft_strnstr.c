/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:17:10 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/02 20:08:56 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	find_match(const char *haystack, const char *needle, size_t len)
{
	while (*needle && *haystack == *needle && len)
	{
		haystack++;
		needle++;
		len--;
	}
	return (*needle == 0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	while ((*haystack && len) || !*needle)
	{
		if (find_match(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
