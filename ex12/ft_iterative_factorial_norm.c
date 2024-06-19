/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial_norm.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:45:49 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/19 15:45:53 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	sum;

	sum = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	while (nb > 0)
	{
		sum *= nb;
		nb--;
	}
	return (sum);
}

/*int	main(void)
{
	int num = 5;
	int sum;
	sum = ft_iterative_factorial(num);
	printf("%d\n", sum);
	return (0);
}*/
