/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:04:29 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/07/08 16:04:42 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*
int	count_if(char *str)
{
	int	count;
	int	num_one;
	int	i;

	count = 0;
	while (*str)
	{
		if (*str == '1')
		{
			count++;
		}
		str++;
	}
	return (count);
}*/
int	ft_count_if(char **tab, int (*f)(char *))
{
	i = 0;
	num_one = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
		{
			num_one++;
		}
		i++;
	}
	return (num_one);
}

/*
int	main(int ac, char **av)
{
	int count = ft_count_if(av + 1, count_if);
	printf("%d\n", count);
	return (0);
}*/