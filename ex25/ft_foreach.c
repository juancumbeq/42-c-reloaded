/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:13:40 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/07/08 11:15:25 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_number(int n)
{
	printf("%d", n);
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(*tab);
		i++;
		tab++;
	}
}

/*
int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	len;

	len = sizeof(array) / sizeof(array[0]);
	ft_foreach(array, len, print_number);
}*/
