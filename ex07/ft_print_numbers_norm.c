/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers_norm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:20:27 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/18 20:21:04 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int	digit;

	digit = 48;
	while (digit <= 57)
	{
		write(1, &digit, 1);
		digit++;
	}
}

int	main(void)
{
	ft_print_numbers();
	return (0);
}
