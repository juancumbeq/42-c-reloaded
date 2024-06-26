/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:38 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/18 16:49:08 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int	c;

	c = 48;
	while (c <= 57)
	{
		ft_putchar(c);
		c++;
	}
}

/*int	main(void)
{
	ft_print_numbers();
	return (0);
}*/
