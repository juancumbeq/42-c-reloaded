/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:44:25 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/19 16:45:19 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	x;

	x = 0;
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while (x <= nb / 2)
	{
		if ((x * x) == nb)
			return (x);
		x++;
	}
	return (0);
}

/*int	main(void)
{
	int num = 26;
	int sqrt;
	sqrt = ft_sqrt(num);
	printf("%d\n", sqrt);
	return (0);
}*/
