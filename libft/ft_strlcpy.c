/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniviei <daniviei@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:16:46 by daniviei          #+#    #+#             */
/*   Updated: 2025/11/04 17:15:36 by daniviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ssize;
	size_t	i;

	i = 0;
	ssize = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ssize);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	*src;
	char	dest[20] = "asfasfg";
	char	*src2;
	char	dest2[20] = "asfasfg";

	src = "deucerto";
	src2 = "deucerto";

	printf("My --> %zu\n", ft_strlcpy(dest, src, 0));
	printf("dest --> %s\n", dest);

	printf("Original -- > %zu\n", strlcpy(dest2, src2, 0));
	printf("dest --> %s\n", dest2);

}*/
