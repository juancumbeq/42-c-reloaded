/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:38 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/16 15:20:16 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Create a function that displays all digits, on a single line, by ascending order.
 *
 * Here's how it should be prototyped: void ft_print_numbers(void)
 */

#include <unistd.h>

void ft_print_numbers(void)
{
	int digit;
	digit = 48;

	while(digit <= 57)
	{
		write(1, &digit,1);
		digit++;
	}
}

int main(void)
{
	ft_print_numbers();
	return(0);
}
