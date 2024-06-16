/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcumbe-q <jcumbe-q@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:41:55 by jcumbe-q          #+#    #+#             */
/*   Updated: 2024/06/10 17:06:29 by jcumbe-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Create a function that displays the alphabet in lowercase, on a sigle line, by ascending order, starting from the letter 'a'. 
 */

#include <unistd.h>

void ft_print_alphabet(void)
{	
	char letter = 'a';
	while(letter <= 'z')
	{
		write(1, &letter, 1);
		letter++;
	}
}

int main(void)
{
	ft_print_alphabet();	
	return(0);
}

/*
 * For C language the characters are also numbers, following the ASCII code. This is the
 * reason we can do 'letter++' because we are adding +1 to the ASCII number that represents
 * the 'a' letter for the first iteration
 */
