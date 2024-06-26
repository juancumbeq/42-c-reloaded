/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:32:01 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/26 17:14:03 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	char	*aux;
	int		len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	copy = malloc(sizeof(char *) * len + 1);
	aux = copy;
	while (*src != '\0')
	{
		*aux = *src;
		aux++;
		src++;
	}
	*aux = '\0';
	return (copy);
}

int	main(void)
{
	char	*src;
	char	*copy;

	src = "Hello world!";
	copy = ft_strdup(src);
	printf("Original: %s\n", src);
	printf("Copy: %s\n", copy);
	free(copy);
	return (0);
}
