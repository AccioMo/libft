/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:00:58 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/03 20:43:42 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > s_len)
		len = (s_len - start) * (start < s_len);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (start-- && *s)
		s++;
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}
