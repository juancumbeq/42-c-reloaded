/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:51:33 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/21 17:52:12 by jcumbe-q         ###   ########.fr       */
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

/*int	main(void)
{
	char *str1 = "Holaa";
	char *str2 = "Hola";
	int cmp;

	cmp = ft_strcmp(str1, str2);

	printf("%d\n", cmp);
	return (0);
}*/
