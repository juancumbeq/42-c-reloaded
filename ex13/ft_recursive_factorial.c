/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:40:05 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/17 13:41:56 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 1)
		nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}

int	main(void)
{
	int num = 5;
	int sum;
	sum = ft_recursive_factorial(num);
	printf("%d\n", sum);
	return (0);
}
