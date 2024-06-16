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

int main (int argc, char *argv[])
{
	char num_char;
	int digit;
	
	num_char = argv[1][0]; // Accesing the firts char of the firts argument.
	digit = (int)num_char; // Casting to convert a char into a string

	ft_is_negative(digit); // Do not work with negative values
}

/*
 * argc and argv: 
 * argc (argument count) is an integer that indicates the number of command-line arguments passed to the program.
 * argv (argument vector) is an array of strings (character pointers) representing the command-line arguments. argv[0] is the name of the program, and argv[1] through argv[argc-1] are the arguments.
 * ARGV es un array de punteros los cuáles hacen referencia a strings o también conocidos como arrays de chars.
 */