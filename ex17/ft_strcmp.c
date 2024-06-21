/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:35:46 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/20 16:36:46 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	cmp;

	while (*s1 != '\0' && *s2 != '\0')
	{
		cmp = *s1 - *s2;
		if (cmp == 0)
		{
			s1++;
			s2++;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (*s1 - *s2);
}

int	main(void)
{
	char *str1 = "Holaa";
	char *str2 = "Hola";
	int cmp;

	cmp = ft_strcmp(str1, str2);

	printf("%d\n", cmp);
	return (0);
}