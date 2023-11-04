/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 01:33:53 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/11/01 19:20:36 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	dstsize -= (dst_len + 1);
	dst += dst_len;
	while (*src && dstsize > 0)
	{
		*dst = *src;
		dstsize--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
