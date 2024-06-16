/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:51:39 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/16 15:55:22 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’.
 */

#include <unistd.h>

void ft_is_negative(int n)
{
	if(n<0)
	{
		write(1,"N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}

int main (void)
{
	ft_is_negative(9);
}
